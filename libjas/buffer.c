/**
 * MIT License
 * Copyright (c) 2023-2024 Alvin Cheng (eventide1029@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @see `LICENSE`
 */

#include "buffer.h"
#include "null.h"
#include <stddef.h>
#include <stdint.h>

void buf_write(buffer_t *buf, const uint8_t *data, const size_t data_len) {
  buf->data = (uint8_t *)(buf->data == NULL ? malloc(data_len) : realloc(buf->data, buf->len + data_len));

  for (size_t i = 0; i < data_len; i++)
    buf->data[buf->len + i] = data[i];

  buf->len += data_len;
}

void buf_remove(buffer_t *buf, const size_t elem) {
  if (buf->len == 0)
    return;

  for (size_t i = elem; i < buf->len - 1; i++)
    buf->data[i] = buf->data[i + 1];

  buf->len--;
  buf->data = realloc(buf->data, buf->len);
}

void buf_remove_chunk(buffer_t *buf, const size_t start, const size_t end) {
  if (buf->len == 0)
    return;

  for (size_t i = start; i < end; i++)
    buf_remove(buf, i);
}