require 'bundler/setup'
require 'rspec/core'
require 'rspec/autorun'
require 'uuidtools'

# Requires supporting files with custom matchers and macros, etc,
# in ./support/ and its subdirectories.
Dir["#{File.dirname(__FILE__)}/support/**/*.rb"].each { |file| require file }

RSpec.configure do |config|
  config.mock_framework = :rspec
end