//
//  CWHessianArchiver+Private.h
//  HessianKit
//
//  Copyright 2008 Fredrik Olsson, Jayway AB. All rights reserved.
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License. 
//  You may obtain a copy of the License at 
// 
//  http://www.apache.org/licenses/LICENSE-2.0 
//  
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, 
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
#import <HessianKit/CWHessianArchiver.h>
#else
#import "CWHessianArchiver.h"
#endif
#import "NSStream+CWAdditions.h"

@class CWDistantHessianObject;

@interface CWHessianArchiver (Private)

-(void)encodeInt:(int)intv forKey:(NSString*)key;
-(void)encodeInteger:(NSInteger)intv forKey:(NSString*)key;

-(void)writeBool:(BOOL)value;
-(void)writeInt32:(int32_t)value;
-(void)writeDouble:(double)value;
-(void)writeDate:(NSDate*)date;
-(void)writeString:(NSString*)string withTag:(char)tag;
-(void)writeData:(NSData*)data withTag:(char)tag;
-(void)writeList:(NSArray*)list;
-(void)writeMap:(NSDictionary*)map;

-(void)writeTypedObject:(id)object;

@end


@interface CWHessianUnarchiver ()

@property(retain, nonatomic) NSDictionary* currentObjectMap;

@end

@interface CWHessianUnarchiver (Private)

-(int)decodeIntForKey:(NSString*)key;
-(NSInteger)decodeIntegerForKey:(NSString*)key;

-(BOOL)readBool;
-(int32_t)readInt32;
-(int64_t)readInt64;
-(double)readDouble;
-(NSDate*)readDate;
-(NSString*)readStringWithTag:(char)tag;
#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
-(NSXMLDocument*)readXMLWithTag:(char)tag;
#endif
-(NSData*)readDataWithTag:(char)tag;
-(NSException*)readFault;
-(NSArray*)readList;
-(id)readMapWithInitialChar:(char)aChar typedObject:(id)typedObject;
-(id)readMap;
-(CWDistantHessianObject*)readRemote;

-(id)readTypedObjectWithInitialChar:(char)aChar;

-(id)readDecodeCandidateForKey:(NSString*)key ofClass:(Class)cls;

@end

