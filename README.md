<p align="center"><img alt="logo and mascot" src="https://github.com/cheng-alvin/jas/assets/88267875/a3b453ce-a0c6-443d-881f-cdcfa34e8ddc">
</p>

<p align="center">
  <!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
<img src='https://img.shields.io/badge/all_contributors-1-orange.svg?style=flat-square' />
<!-- ALL-CONTRIBUTORS-BADGE:END -->
<img alt='PRs Welcome' src='https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=shields'/>
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/cheng-alvin/jas">
  <img alt="GitHub License" src="https://img.shields.io/github/license/cheng-alvin/jas">
  <img alt="GitHub closed issues" src="https://img.shields.io/github/issues-closed/cheng-alvin/jas"/>
</p>

|⚠️ | Jas is under development and is **NOT STABLE** for use. Please make sure it's NOT used for production purposes!! **NO WARRANTY WILL BE PROVIDED AS PER THE LICENSE**|
| -------- | ------- |

Jas is a minimal, fast and simple zero-dependdency assembler for the x64 family of processors, jas not only aims to be fast and simple when using it but also aims to be a learning reasource for others to learn about low-level system programming and the x64 instruction set.

### 🏗️ Basic usage

```c
#include <codegen.h>

int main(void) {
  instruction_t instr[] = (instruction_t[]) {

    // label:
    (instruction_t) {
      .instr = (enum instructions) NULL, .operands = NULL
    },

    // mov rax, 60
    (instruction_t) {
      .instr = INSTR_MOV,
        .operands = (operand_t[]) {
          (operand_t) {
            .type = OP_R64,
              .data = & (enum registers) {
                REG_RAX
              },
          },
          (operand_t) {
            .type = OP_IMM64,
              .data = & (uint64_t) {
                60
              },
          },
          OP_NONE,
          OP_NONE,
        },
    },

    // jmp label
    (instruction_t) {
      .instr = INSTR_JMP,
        .operands = (operand_t[]) {
          (operand_t) {
            .type = OP_REL8,
              .data = & (char[]) {
                "label"
              },
          },
          OP_NONE,
          OP_NONE,
          OP_NONE,
        },
    },
  };

  buffer_t buf = codegen(MODE_LONG, instr, sizeof(instr));
  free(buf.data);
}
```

Yeah! that's it! Seriously! Also remember to install/link against the binary releases **[add link]** or build it from source with following the instructions [here](https://github.com/cheng-alvin/jas/blob/dev/CONTRIBUTING.md)

### 📝 Licensing 
All the code under the Jas assembler project repository is licensed under the [MIT license](https://en.wikipedia.org/wiki/MIT_License) which is a popular open-source license for projects like this! Please see [LICENSE](https://github.com/cheng-alvin/jas/blob/main/LICENSE) for the details.

*No warranty of any kind is provided, please double check offical sources before deploying code to production*

### ❤️ Contributing / Security issues
No software is perfect, nor is Jas. As the assembler is written in C, many secuity issues may arise, causing issues across the program. It's a shared responsibility to safeguard Jas of all developers, contributers and users alike. Please report all secuity concerns in a timely manner via email or the means provided [here](https://github.com/cheng-alvin/jas/blob/dev/SECURITY.md). 

However, for developers interested and passionate about assemblers and low-level programming, please see the [contributing guide](https://github.com/cheng-alvin/jas/blob/a02fea10d9d398ef63a9fc9419ce54d8b406c3a5/CONTRIBUTING.txt) in the home directory for more information on how to contribute code to the repository! 

All changes and reports are welcome, no matter how big or small your changes are :-)

---
*Made with love by Alvin / the Jas crew and contributors ❤️ .* 
