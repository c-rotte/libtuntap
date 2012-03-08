/*
 * Copyright (c) 2012 Tristan Le Guern <leguern AT medu DOT se>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include <stdio.h>
#include <unistd.h>
#include "tun.h"

int
main(void) {
	struct device *dev;

	dev = tnt_tt_init();
	if (tnt_tt_start(dev, TNT_TUNMODE_TUNNEL, 0) == -1) {
		return 1;
	}

	if (tnt_tt_set_ip(dev, "1.2.3.4", "255.255.255.0") == -1) {
		return 1;
	}

	if (tnt_tt_up(dev) == -1) {
		return 1;
	}

	if (tnt_tt_down(dev) == -1) {
		return 1;
	}

	tnt_tt_destroy(dev);
	return 0;
}

