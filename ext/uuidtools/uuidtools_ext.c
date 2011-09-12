#include "ruby.h"
#include <string.h>

VALUE mUUIDTools = Qnil;
VALUE cUUID = Qnil;

/*
def generate_s
  result = sprintf("%8.8x-%4.4x-%4.4x-%2.2x%2.2x-", @time_low, @time_mid,
    @time_hi_and_version, @clock_seq_hi_and_reserved, @clock_seq_low);
  for i in 0..5
    result << sprintf("%2.2x", @nodes[i])
  end
  return result.downcase
end
*/

static VALUE rb_uuidtools_uuid_generate_s(VALUE self)
{

  VALUE time_low = rb_iv_get(self, "@time_low");
  VALUE time_mid = rb_iv_get(self, "@time_mid");
  VALUE time_hi_and_version = rb_iv_get(self, "@time_hi_and_version");
  VALUE clock_seq_hi_and_reserved = rb_iv_get(self, "@clock_seq_hi_and_reserved");
  VALUE clock_seq_low = rb_iv_get(self, "@clock_seq_low");
  VALUE nodes = rb_iv_get(self, "@nodes");

  char uuid[37];
  sprintf(uuid, "%8.8x-%4.4x-%4.4x-%2.2x%2.2x-", NUM2ULONG(time_low), NUM2ULONG(time_mid),
    NUM2ULONG(time_hi_and_version), NUM2ULONG(clock_seq_hi_and_reserved), NUM2ULONG(clock_seq_low));

  struct RArray *nodes_array = RARRAY(nodes);

  size_t i;
  for(i = 0; i < nodes_array->len; i++)
  {
    sprintf(uuid + 24 + (i*2), "%2.2x", NUM2ULONG(nodes_array->ptr[i]));
  }

  return rb_str_new2(uuid);
}

static VALUE rb_uuidtools_uuid_parse(VALUE mod, VALUE uuid_string)
{
  const char *separators = "-";
  char *uuid_str = STR2CSTR(uuid_string);
  char *strok_r_ptr = NULL;

  // 11111111-0000-0000-0000-000000000000
  char *time_low_str = strtok_r(uuid_str, separators, &strok_r_ptr);

  // 00000000-1111-0000-0000-000000000000
  char *time_mid_str = strtok_r(NULL, separators, &strok_r_ptr);

  // 00000000-0000-1111-0000-000000000000
  char *time_hi_and_version_str = strtok_r(NULL, separators, &strok_r_ptr);

  // 00000000-0000-0000-1111-000000000000
  char *combined = strtok_r(NULL, separators, &strok_r_ptr);
  if (combined == NULL || strlen(combined) != 4) {
    rb_raise(rb_eArgError, "Invalid UUID format");
  }
  // 00000000-0000-0000-1100-000000000000
  char clock_seq_hi_and_reserved_str[3];
  strncpy(clock_seq_hi_and_reserved_str, combined, 2);

  // 00000000-0000-0000-0011-000000000000
  char clock_seq_low_str[3];
  strncpy(clock_seq_low_str, combined + 2, 2);

  // 00000000-0000-0000-0000-111111111111
  char *remaining = strtok_r(NULL, separators, &strok_r_ptr);
  if (time_low_str == NULL || time_mid_str == NULL || time_hi_and_version_str == NULL ||
      clock_seq_hi_and_reserved_str == NULL || clock_seq_low_str == NULL) {
    rb_raise(rb_eArgError, "Invalid UUID format");
  }

  char *strtol_ptr = NULL;
  VALUE time_low = rb_int2inum(strtol(time_low_str, &strtol_ptr, 16));
  VALUE time_mid = rb_int2inum(strtol(time_mid_str, &strtol_ptr, 16) & 0x00ffff);
  VALUE time_hi_and_version = rb_int2inum(strtol(time_hi_and_version_str, &strtol_ptr, 16) & 0x00ffff);
  VALUE clock_seq_hi_and_reserved = rb_int2inum(strtol(clock_seq_hi_and_reserved_str, &strtol_ptr, 16) & 0x0000ff);
  VALUE clock_seq_low = rb_int2inum(strtol(clock_seq_low_str, &strtol_ptr, 16) & 0x0000ff);
  VALUE nodes = rb_ary_new();

  if (remaining == NULL || strlen(remaining) != 12) {
    rb_raise(rb_eArgError, "Invalid UUID format");
  }

  size_t i;
  for(i=0; i < 6; ++i)
  {
    char nibble[3];
    strncpy(nibble, remaining + (i*2), 2);
    rb_ary_push(nodes, rb_int2inum(strtol(nibble, &strtol_ptr, 16) & 0x0000ff));
  }

  return rb_funcall(cUUID, rb_intern("new"), 6, time_low, time_mid, time_hi_and_version,
    clock_seq_hi_and_reserved, clock_seq_low, nodes);
}

void Init_uuidtools() {
  mUUIDTools = rb_define_module("UUIDTools");
  cUUID = rb_define_class_under(mUUIDTools, "UUID", rb_cObject);

  rb_define_singleton_method(cUUID, "parse", rb_uuidtools_uuid_parse, 1);
  rb_define_method(cUUID, "generate_s", rb_uuidtools_uuid_generate_s, 0);
}