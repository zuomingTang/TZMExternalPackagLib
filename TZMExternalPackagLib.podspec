#
# Be sure to run `pod lib lint TZMExternalPackagLib.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TZMExternalPackagLib'
  s.version          = '0.1.2'
  s.summary          = 'TZMExternalPackagLib.'
  
  s.subspec 'iflyMSC' do |si|
      si.frameworks = 'AVFoundation', 'SystemConfiguration', 'Foundation', 'CoreTelephony', 'AudioToolbox', 'UIKit', 'CoreLocation', 'QuartzCore', 'CoreGraphics', 'Contacts', 'AddressBook'
      si.libraries = 'z','c++'
      si.vendored_frameworks = 'TZMExternalPackagLib/Classes/iflyMSC/iflyMSC.framework'
      si.requires_arc = false
  end


  s.description      = <<-DESC
TODO: TZMExternalPackagLib
                       DESC

  s.homepage         = 'https://github.com/zuomingTang/TZMExternalPackagLib'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zuomingTang' => '414933949@qq.com' }
  s.source           = { :git => 'https://github.com/zuomingTang/TZMExternalPackagLib.git', :tag => '0.1.2' }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  
  s.source_files = 'TZMExternalPackagLib/Classes/*'
  s.public_header_files = 'TZMExternalPackagLib/Classes/*.h'
end
