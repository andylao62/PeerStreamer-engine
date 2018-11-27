/*
 * Copyright (c) 2010-2011 Luca Abeni
 * Copyright (c) 2010-2011 Csaba Kiraly
 * Copyright (c) 2017 Luca Baldesi
 *
 * This file is part of PeerStreamer.
 *
 * PeerStreamer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * PeerStreamer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with PeerStreamer.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef INPUT_H
#define INPUT_H

#include<psinstance.h>

#define INPUT_LOOP 0x0001
#define INPUT_UDP 0x0002
#define INPUT_IPB 0x0004

struct input_desc;
struct chunk;

struct input_context {
	char filename[80];
	int fds[FDSSIZE];
	int fds_size;
};

struct input_desc *input_open(struct input_context * ctx, const char * config);
void input_close(struct input_desc *s);

/*
 * c: chunk structure to be filled. If c->data = NULL after call, there is no new chunk
 * Returns: timeout requested till next call to the function, <0 in case of input error, INT_MAX if no timeout is requested
 */
int input_get(struct input_desc *s, struct chunk *c);

struct chunk *input_chunk(struct input_desc * s, suseconds_t *delta);

#endif	/* INPUT_H */
