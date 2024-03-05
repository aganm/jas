#ifndef BTS_H
#define BTS_H

#include "init.h"
#include "operand.h"

/**
 * Function for Generating the code for the `bts` instruction, normally
 * used internally. Please call this function through the `jasCodegen()` function.
 *
 * @param op1 The first operand to be encoded.
 * @param op2 The second operand to be encoded.
 * @param op3 The third operand to be encoded.
 * @param op4 The fourth operand to be encoded.
 * @param instance The instance of the assembler unit.
 *
 * @returns The error code if the encoding was successful.
 *
 * @note All operands except the first two operands are not required. Please refer to the
 * the intel manual for more information on the `bts` instruction.
 *
 * @warning This is NOT an assembly tutorial. Please see other resources for
 * more information on the `bts` instruction. We expect that you know assembly and
 * basic programming concepts.
 */

jasErrorCode_t jasBTS(jasTaggedOperand_t op1, jasTaggedOperand_t op2, jasTaggedOperand_t op3, jasTaggedOperand_t op4, jasInstance_t *instance);

#endif
