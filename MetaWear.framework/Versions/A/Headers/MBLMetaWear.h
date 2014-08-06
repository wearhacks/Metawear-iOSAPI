//
//  MBLMetaWear.h
//  MetaWear
//
//  Created by Stephen Schiffli on 7/29/14.
//  Copyright (c) 2014 MbientLab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <MetaWear/MBLConstants.h>

@class MBLTemperature;
@class MBLAccelerometer;
@class MBLLED;
@class MBLMechanicalSwitch;
@class MBLGPIO;
@class MBLHapticDriver;
@class MBLiBeacon;

@interface MBLMetaWear : NSObject <CBPeripheralDelegate>

/**
 Query the current RSSI
 */
- (void)readRSSIWithHandler:(MBLNumberHandler)handler;
/**
 Query the percent remaining battery life, returns int between 0-100
 */
- (void)readBatteryLifeWithHandler:(MBLNumberHandler)handler;

/** 
 Pointer the underlying CoreBluetooth object 
 */
@property (nonatomic, strong, readonly) CBPeripheral *peripheral;
/** 
 Stored value of signal strength at discovery time 
 */
@property (nonatomic, strong, readonly) NSNumber *discoveryTimeRSSI;

// *** Sensors ***
@property (nonatomic, strong, readonly) MBLMechanicalSwitch *mechanicalSwitch;
@property (nonatomic, strong, readonly) MBLLED *led;
@property (nonatomic, strong, readonly) MBLTemperature *temperature;
@property (nonatomic, strong, readonly) MBLAccelerometer *accelerometer;
@property (nonatomic, strong, readonly) MBLGPIO *gpio;
@property (nonatomic, strong, readonly) MBLHapticDriver *hapticDriver;
@property (nonatomic, strong, readonly) MBLiBeacon *iBeacon;

@end
