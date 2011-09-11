require "rake/extensiontask"

Rake::ExtensionTask.new('uuidtools') do |ext|
  ext.lib_dir = File.join('lib', 'uuidtools')

  CLEAN.include "#{ext.lib_dir}/*.#{RbConfig::CONFIG['DLEXT']}"
end