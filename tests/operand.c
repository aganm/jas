#include "operand.h"
#include "buffer.h"
#include "encoder.h"
#include "rex.h"
#include "test.h"

Test(operand, write_prefix) {
  buffer_t buf = BUF_NULL;

  const operand_t op_arr16[] = {r16, imm16, OP_NONE, OP_NONE};
  const operand_t op_addr16[] = {m16, imm16, OP_NONE, OP_NONE};
  const operand_t op_arr32[] = {r32, imm32, OP_NONE, OP_NONE};
  const operand_t op_addr32[] = {m32, imm32, OP_NONE, OP_NONE};
  const operand_t op_arr64[] = {r64, imm64, OP_NONE, OP_NONE};
  const operand_t op_addr64[] = {m64, imm64, OP_NONE, OP_NONE};

#define RUN_TEST(operands, mode, index, expected) \
  op_write_prefix(&buf, operands, mode);          \
  assert_eq(buf.data[index], expected);

  RUN_TEST(op_arr16, MODE_PROTECTED, 1, 0x66);
  RUN_TEST(op_addr16, MODE_PROTECTED, 2, 0x67);
  RUN_TEST(op_arr32, MODE_REAL, 3, 0x66);

  op_write_prefix(&buf, op_addr32, MODE_REAL);
  assert_eq(buf.data[4], 0x66);
  assert_eq(buf.data[5], 0x67);

  RUN_TEST(op_arr64, MODE_LONG, 6, REX_W);
  RUN_TEST(op_addr64, MODE_LONG, 7, REX_W);
  free(buf.data);
}

Test(operand, construct_operand) {
  const operand_t byte = op_construct_operand(OP_IMM8, 0, &(unsigned char){0xFF});

  assert_eq(byte.type, OP_IMM8);
  assert_eq(byte.offset, 0);
  assert_eq(*(unsigned char *)byte.data, 0xFF);
}

Test(operand, ident_identify) {
  const enum operands input[] = {OP_R8, OP_R16, OP_NULL, OP_NULL};
  const enum operands input2[] = {OP_R8, OP_M16, OP_NULL, OP_NULL};

  assert_eq(op_ident_identify(input), OP_MR);
  assert_eq(op_ident_identify(input2), OP_RM);
}

int main(void) {
  TestSuite(operand);

  RunTest(operand, write_prefix);
  RunTest(operand, construct_operand);
  RunTest(operand, ident_identify);

  return 0;
}
