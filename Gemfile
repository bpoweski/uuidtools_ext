source "http://rubygems.org"

# Specify your gem's dependencies in uuidtools_ext.gemspec
gemspec

group :development do
  gem 'rcov',          :platforms => :mri_18
  gem 'ruby-debug',    :platforms => :mri_18
  gem 'ruby-debug19',  :platforms => :mri_19, :require => 'ruby-debug' if RUBY_VERSION < "1.9.3"
  gem 'spec_coverage', :platforms => :mri_19, :require => false
  gem 'ruby-prof',     :platforms => :mri_18
end