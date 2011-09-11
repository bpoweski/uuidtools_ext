require 'bundler/gem_tasks'
require 'rspec/core/rake_task'

task :default => 'spec:rcov'

Dir['tasks/**/*.rake'].each { |rake| load rake }

Rake::Task['spec:rcov'].prerequisites << :compile
Rake::Task['spec'].prerequisites << :compile
