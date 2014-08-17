//
//  OSCache.h
//
//  Version 1.1.1
//
//  Created by Nick Lockwood on 01/01/2014.
//  Copyright (C) 2014 Charcoal Design
//
//  Distributed under the permissive zlib License
//  Get the latest version from here:
//
//  https://github.com/nicklockwood/OSCache
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#import <Foundation/Foundation.h>


@interface OSCache : NSCache

- (NSUInteger)count;
- (NSUInteger)totalCost;

// Kurt Arnlund - Ingenious Arts and Technologies LLC - 8/16/2014
// added object subscripting so that ELAWellCached could work with this cache.
// NSCache may have supported object subscripting as well since ELAWellCached made use of it.
- (id)objectForKeyedSubscript:(id <NSCopying>)key;
- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

@end


@protocol OSCacheDelegate <NSCacheDelegate>
@optional

- (BOOL)cache:(OSCache *)cache shouldEvictObject:(id)entry;
- (void)cache:(OSCache *)cache willEvictObject:(id)entry;

@end
