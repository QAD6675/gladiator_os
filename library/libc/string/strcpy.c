/*
 * strcpy function
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

char* strcpy(char* restrict s1, const char* restrict s2) {
	while (*s2 != '\0') {
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return s1;
}
