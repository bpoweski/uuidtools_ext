desc "Benchmark each UUID generation method"
task :benchmark do
  require 'uuidtools'
  require 'benchmark'

  # Version 1
  result = Benchmark.measure do
    10000.times do
      UUIDTools::UUID.timestamp_create.to_s
    end
  end
  puts "#{(10000.0 / result.real)} version 1 per second."

  # Version 3
  result = Benchmark.measure do
    10000.times do
      UUIDTools::UUID.md5_create(UUIDTools::UUID_URL_NAMESPACE,
        "http://www.ietf.org/rfc/rfc4122.txt").to_s
    end
  end
  puts "#{(10000.0 / result.real)} version 3 per second."

  # Version 4
  result = Benchmark.measure do
    10000.times do
      UUIDTools::UUID.random_create.to_s
    end
  end
  puts "#{(10000.0 / result.real)} version 4 per second."

  # Version 5
  result = Benchmark.measure do
    10000.times do
      UUIDTools::UUID.sha1_create(UUIDTools::UUID_URL_NAMESPACE,
        "http://www.ietf.org/rfc/rfc4122.txt").to_s
    end
  end
  puts "#{(10000.0 / result.real)} version 5 per second."
end
