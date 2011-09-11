require 'bundler/gem_tasks'
require 'rspec/core/rake_task'

task :default => 'spec:cov'

Dir['tasks/**/*.rake'].each { |rake| load rake }