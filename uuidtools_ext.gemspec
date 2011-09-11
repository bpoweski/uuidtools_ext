# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "uuidtools/version"

Gem::Specification.new do |s|
  s.name        = "uuidtools_ext"
  s.version     = UUIDTools::VERSION
  s.authors     = ["Bob Aman", "Ben Poweski"]
  s.email       = "bob@sporkmonger.com"
  s.homepage    = "http://github.com/bpoweski/uuidtools_ext"
  s.summary     = %q{TODO: Write a gem summary}
  s.description = %q{TODO: Write a gem description}

  s.rubyforge_project = "uuidtools_ext"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]

  s.add_development_dependency "rspec"
  s.add_development_dependency "rake"
end
