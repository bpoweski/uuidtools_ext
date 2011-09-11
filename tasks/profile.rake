desc "execute RubyProf against UUID.sha1_create"
task :profile do
  require 'uuidtools'
  require 'ruby-prof'

  result = RubyProf.profile do
    10000.times do
      UUIDTools::UUID.sha1_create(UUIDTools::UUID_URL_NAMESPACE,
        "http://www.ietf.org/rfc/rfc4122.txt").to_s
    end
  end

  # Print a graph profile to text
  printer = RubyProf::GraphHtmlPrinter.new(result)
  file = File.open("profile.html", "w")
  printer.print(file, :min_percent => 1)
end
