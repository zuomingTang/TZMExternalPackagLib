#
# Be sure to run `pod lib lint TZMExternalPackagLib.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TZMExternalPackagLib'
  s.version          = '0.1.7.2'
  s.summary          = 'TZMExternalPackagLib.'
  
  s.subspec 'EZOpenSDK' do |sez|
      sez.requires_arc = true
      sez.vendored_frameworks = 'TZMExternalPackagLib/Classes/EZOpenSDK/EZOpenSDKFramework.framework'
  end
  
  s.subspec 'iflyMSC' do |si|
      si.frameworks = 'AVFoundation', 'SystemConfiguration', 'Foundation', 'CoreTelephony', 'AudioToolbox', 'UIKit', 'CoreLocation', 'QuartzCore', 'CoreGraphics', 'Contacts', 'AddressBook'
      si.libraries = 'z','c++'
      si.vendored_frameworks = 'TZMExternalPackagLib/Classes/iflyMSC/iflyMSC.framework'
      si.requires_arc = false
  end
  
  s.subspec 'TencentOpenApi' do |st|
      st.frameworks          = 'Security', 'SystemConfiguration', 'CoreGraphics', 'CoreTelephony'
      st.libraries           = 'iconv', 'sqlite3', 'stdc++', 'z'
      st.vendored_frameworks = 'TZMExternalPackagLib/Classes/TencentOpenApi/TencentOpenAPI.framework'
      st.requires_arc = false
  end
  
  s.subspec 'KooKongSDK' do |sk|
      sk.libraries            = 'z.1.2.5'
      sk.source_files         = 'TZMExternalPackagLib/Classes/KooKongSDK/*.{h}'
      sk.vendored_libraries   = 'TZMExternalPackagLib/Classes/KooKongSDK/*.a'
      sk.pod_target_xcconfig  = { 'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) _7ZIP_ST' }
      sk.requires_arc = false
  end
  
  s.subspec 'EnjoyHomeOpenSDK' do |se|
      se.source_files         = 'TZMExternalPackagLib/Classes/EnjoyHomeOpenSDK/*.{h}'
      se.vendored_libraries   = 'TZMExternalPackagLib/Classes/EnjoyHomeOpenSDK/*.a'
      se.requires_arc = false
  end
  
  s.subspec 'JdPlaySdk' do |sj|
      sj.frameworks = 'SystemConfiguration', 'AVFoundation', 'Foundation', 'CoreTelephony', 'AudioToolbox', 'UIKit', 'CoreLocation', 'QuartzCore', 'CoreGraphics', 'Contacts', 'AddressBook'
      sj.libraries = 'stdc++','z.1.2.5'
      sj.vendored_frameworks = 'TZMExternalPackagLib/Classes/JdPlaySdk/JdPlaySdk.framework'
      sj.dependency 'Reachability', '3.2'
      sj.dependency 'MJRefresh', '3.2.2'
      sj.dependency 'MJExtension', '3.2.1'
      sj.dependency 'SDWebImage', '4.2.2'
      sj.requires_arc = false
  end

  s.description      = <<-DESC
TODO: TZMExternalPackagLib
                       DESC

  s.homepage         = 'https://github.com/zuomingTang/TZMExternalPackagLib'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zuomingTang' => '414933949@qq.com' }
  s.source           = { :git => 'https://github.com/zuomingTang/TZMExternalPackagLib.git', :tag => '0.1.7.2' }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  
  s.source_files = 'TZMExternalPackagLib/Classes/*'
  s.public_header_files = 'TZMExternalPackagLib/Classes/*.h'
end
