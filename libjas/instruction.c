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

#include "instruction.h"
#include "error.h"
#include "mi.h"
#include "mr.h"
#include "oi.h"
#include "operand.h"
#include "rm.h"
#include <stdbool.h>
#include <stddef.h>

instr_encode_table_t mov[] = {
    {
        .ident = OP_MR,
        .opcode_ext = NULL,
        .opcode = {0x89},
        .support = NULL,
        .byte_instr_opcode = {0x88},
        .should_fallback_support = false,
        .opcode_size = 1,
        .pre = NULL,
    },
    {
        .ident = OP_RM,
        .opcode_ext = NULL,
        .opcode = {0x8B},
        .support = NULL,
        .byte_instr_opcode = {0x8A},
        .should_fallback_support = false,
        .opcode_size = 1,
        .pre = NULL,
    },
    {
        .ident = OP_OI,
        .opcode_ext = NULL,
        .opcode = {0xB8},
        .support = NULL,
        .byte_instr_opcode = {0xB0},
        .should_fallback_support = false,
        .opcode_size = 1,
        .pre = NULL,

    },
    {
        .ident = OP_MI,
        .opcode_ext = 0b10000000, // Prevents a false null reading, it gets shifted anyways ;)
        .opcode = {0xC7},
        .support = NULL,
        .byte_instr_opcode = {0xC6},
        .should_fallback_support = false,
        .opcode_size = 1,
        .pre = NULL,
    },

    INSTR_TERMINATOR

};

// Experimental
static void pre_lea(operand_t *op_arr, buffer_t *buf, instr_encode_table_t *instr_ref, enum modes mode) {
  if (op_m(op_arr[0].type) || op_r(op_arr[1].type))
    err("Invalid operands type for LEA instruction.");

  if (op_sizeof(op_arr[0].type) == 8)
    err("Byte operands cannot be used with the LEA instruction.");
}

instr_encode_table_t lea[] = {
    {
        .ident = OP_RM,
        .opcode_ext = NULL,
        .opcode = {0x8D},
        .support = NULL,
        .byte_instr_opcode = {0x8D},
        .should_fallback_support = false,
        .opcode_size = 1,
        .pre = &pre_lea,
    },

    INSTR_TERMINATOR

};

instr_encode_table_t *instr_table[] = {mov, lea};

instr_encoder_t instr_encode_func(enum op_ident input) {
  instr_encoder_t lookup[] = {&mr, &rm, &oi, &mi};
  return lookup[(size_t)input];
}
