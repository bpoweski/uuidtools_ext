require "uuidtools/version"
require "uuidtools/uuid"

module UUIDTools
  UUID_DNS_NAMESPACE  = UUID.parse("6ba7b810-9dad-11d1-80b4-00c04fd430c8")
  UUID_URL_NAMESPACE  = UUID.parse("6ba7b811-9dad-11d1-80b4-00c04fd430c8")
  UUID_OID_NAMESPACE  = UUID.parse("6ba7b812-9dad-11d1-80b4-00c04fd430c8")
  UUID_X500_NAMESPACE = UUID.parse("6ba7b814-9dad-11d1-80b4-00c04fd430c8")
end
