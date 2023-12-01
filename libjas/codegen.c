#include "codegen.h"
#include "aaa.h"
#include "error.h"
#include "init.h"
#include "instruction.h"
#include "null.h"
#include <stdint.h>

jasErrorCode_t codegen(jasInstruction_t instruction, jasOperand_t op1, jasOperand_t op2, jasOperand_t op3, jasOperand_t op4, uint8_t *buf, jasInstance_t instance) {
  if (buf == NULL)
    return JAS_ERROR_UNDEFINED_POINTER;

  jasInstructionEncoderPointerArray_t jasInstructionEncoder = {&aaa};

  if (instruction > sizeof(jasInstructionEncoder) / sizeof(&aaa))
    return JAS_ERROR_INVALID_INSTRUCTION;

  jasInstructionEncoder[instruction](op1, op2, op3, op4, buf, instance);

  return JAS_NO_ERROR;
}
