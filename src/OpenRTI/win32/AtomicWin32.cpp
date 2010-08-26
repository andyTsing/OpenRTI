/* -*-c++-*- OpenRTI - Copyright (C) 2004-2010 Mathias Froehlich 
 *
 * This file is part of OpenRTI.
 *
 * OpenRTI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * OpenRTI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenRTI.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Atomic.h"

#include <windows.h>

#if !defined OpenRTI_ATOMIC_USE_LIBRARY
#error win32 atomics need a library implementation
#endif

namespace OpenRTI {

unsigned
Atomic::inc()
{
  return InterlockedIncrement(&_value);
}

unsigned
Atomic::dec()
{
  return InterlockedDecrement(&_value);
}

unsigned
Atomic::get() const
{
  MemoryBarrier();
  return _value;
}

bool
Atomic::cmpxch(unsigned oldValue, unsigned newValue)
{
  return oldValue == InterlockedCompareExchange(&_value, newValue, oldValue);
}

}
