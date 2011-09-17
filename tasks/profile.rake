def with_profiling(filename)
  result = RubyProf.profile do
    yield
  end

  # Print a graph profile to text
  printer = RubyProf::GraphHtmlPrinter.new(result)
  file = File.open("coverage/" + filename, "w")
  printer.print(file, :min_percent => 1)
end

desc "execute RubyProf against UUID.sha1_create"
task :profile do
  require 'uuidtools'
  require 'ruby-prof'

  with_profiling("profile_sha1_create.html") do
    10000.times do
      UUIDTools::UUID.sha1_create(UUIDTools::UUID_URL_NAMESPACE, "http://www.ietf.org/rfc/rfc4122.txt").to_s
    end
  end

  with_profiling("profile_parse_raw.html") do
    10000.times do
      UUIDTools::UUID.sha1_create(UUIDTools::UUID.parse_raw("6ba7b810-9dad-11d1-80b4-00c04fd430c8"), "1234").to_s
    end
  end
end
