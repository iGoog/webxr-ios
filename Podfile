# Uncomment the next line to define a global platform for your project
platform :ios, '11.0'

target 'XRViewer' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
    use_frameworks!

  # Pods for ArDemo
  # https://github.com/CocoaLumberjack/CocoaLumberjack/issues/882
    pod 'CocoaLumberjack'
    pod 'PopupDialog'
    pod 'pop'
    pod 'MozillaTelemetry', :git => 'https://github.com/mozilla-mobile/telemetry-ios.git', :branch => 'master'
end


# Enable DEBUG flag in Swift for SwiftTweaks
post_install do |installer|
    installer.pods_project.targets.each do |target|
        if target.name == 'PopupDialog' || target.name == 'MozillaTelemetry'
            target.build_configurations.each do |config|
                config.build_settings['SWIFT_VERSION'] = 'Swift 3.2'
            end
        end
    end
end
