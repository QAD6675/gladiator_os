/*
 * fread function
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

size_t fread(void* restrict ptr, size_t size, size_t nmemb, FILE* restrict stream) {
	if (!size) {
		return 0;
	}
	if (!nmemb) {
		return 0;
	}
	for (size_t i = 0; i < nmemb; i++) {
		if (read(stream->fd, ptr + i * size, size) <= 0) {
			return i;
		}
	}
	return nmemb;
}
