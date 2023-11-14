#include <stdint.h>

/**
 * @author cheng-alvin
 * @since v0.0.1
 *
 * Converts 16, 32 and 64 bit unsigned integers to little endian
 * values respectively. This is used for the code generation process
 * and is portable to another codebase.
 *
 * @param value A 16, 32 or 64 bit unsigned integer in big endian to
 * be converted into little endian number.
 *
 * @returns The little endian result with the same size as the parameter.
 */

uint16_t JAS_little_endian_16(uint16_t value);
uint32_t JAS_little_endian_32(uint32_t value);
uint64_t JAS_little_endian_64(uint64_t value);