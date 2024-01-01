#include "codegen.h"
#include "error.h"
#include "init.h"
#include "macro.h"
#include "mi.h"
#include "modrm.h"
#include "mr.h"
#include "null.h"
#include "operand.h"
#include "rex.h"
#include "rm.h"
#include "write.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

jasErrorCode_t jasAND(jasTaggedOperand_t op1, jasTaggedOperand_t op2, jasTaggedOperand_t op3, jasTaggedOperand_t op4, jasInstance_t *instance);
