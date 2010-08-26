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

#include "Mutex.h"

#include "MutexPrivateDataWin32.h"

namespace OpenRTI {

Mutex::Mutex(void) :
  _privateData(new PrivateData)
{
}

Mutex::~Mutex(void)
{
  delete _privateData;
  _privateData = 0;
}

void
Mutex::lock(void) const
{
  _privateData->lock();
}

void
Mutex::unlock(void) const
{
  _privateData->unlock();
}

} // namespace OpenRTI
