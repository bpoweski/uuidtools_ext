#include "ruby.h"

VALUE mUUIDTools = Qnil;

// The initialization method for this module
void Init_uuidtools_ext() {
  mUUIDTools = rb_define_module("UUIDTools");
}