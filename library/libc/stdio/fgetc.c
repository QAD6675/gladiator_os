/*
 * fgetc function
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

#include <gladiatoros.h>
#include <stdio.h>

int fgetc(FILE* stream) {
	char c;
	if (read(stream->fd, &c, 1) <= 0) {
		return EOF;
	}
	return c;
}
