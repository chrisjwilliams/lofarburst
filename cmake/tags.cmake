# Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA 

# Generate tag files
IF(UNIX)
  # -- this assumes the use of "exuberant ctags"
  if(NOT TARGET tags)
      ADD_CUSTOM_COMMAND(
        OUTPUT tags 
        COMMAND ctags --extra=+f -R -f ${CMAKE_BINARY_DIR}/tags ${CMAKE_SOURCE_DIR}
      )
  endif(NOT TARGET tags)
  if(NOT TARGET ctags)
    add_custom_target(ctags DEPENDS tags) 
  endif(NOT TARGET ctags)

ENDIF()

