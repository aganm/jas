#include "codegen.h"
#include "error.h"
#include "init.h"
#include "macro.h"
#include "modrm.h"
#include "null.h"
#include "operand.h"
#include "rex.h"
#include "rm.h"
#include "write.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @author cheng-alvin
 * @since v0.0.1
 *
 * Function for Generating the code for the `bt` instruction, normally
 * used internally. Please call this function through the `codegen()` function.
 *
 * @param op1 The first operand to be encoded.
 * @param op2 The second operand to be encoded.
 * @param op3 The third operand to be encoded.
 * @param op4 The fourth operand to be encoded.
 * @param instance The instance of the assembler unit.
 *
 * @returns The error code if the encoding was successful.
 *
 * @note All operands except the fourth operand is not required.Please refer to the
 * the intel manual for more information on the `bt` instruction.
 *
 * @warning This is NOT an assembly tutorial. Please see other resources for
 * more information on the `bt` instruction. We expect that you know assembly and
 * basic programming concepts.
 */

jasErrorCode_t jasBT(jasTaggedOperand_t op1, jasTaggedOperand_t op2, jasTaggedOperand_t op3, jasTaggedOperand_t op4, jasInstance_t *instance);