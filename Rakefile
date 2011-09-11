require 'bundler/gem_tasks'
require 'rspec/core/rake_task'

task :default => 'spec:cov'

RSpec::Core::RakeTask.new

namespace :spec do
  RSpec::Core::RakeTask.new(:cov) do |task|
    if RUBY_VERSION < "1.9"
      task.rcov      = true
      task.rcov_opts = "--failure-threshold 80 --exclude test/*,spec/*,features/*,gems/*"
    else
      task.rspec_opts = "--format SpecCoverage --format nested"
    end
  end
end

Dir['tasks/**/*.rake'].each { |rake| load rake }