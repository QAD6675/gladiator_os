/*
 * readdir function
 *
 * This file is part of GLADIATOROS.
 *
 * GLADIATOROS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GLADIATOROS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GLADIATOROS.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <dirent.h>
#include <gladiatoros.h>

struct dirent* readdir(DIR* dirp) {
	static struct dirent dire;
	if (!dir_read(dirp->fd, dire.d_name)) {
		return 0;
	}
	return &dire;
}
