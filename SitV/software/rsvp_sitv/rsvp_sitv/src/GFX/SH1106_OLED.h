#ifndef SH1106_OLED_H_
#define SH1106_OLED_H_

#include <stdint.h>
#include <string.h>

struct SH1106_OLED {
  static constexpr size_t kFrameSize = 128 * 64 / 8;
  static constexpr size_t kNumPages = 8;
  static constexpr size_t kPageSize = kFrameSize / kNumPages;
  static constexpr uint8_t kDefaultOffset = 2;


  static void Init();
  static void Clear();
  static void Flush();
  static void SendPage(uint_fast8_t index, const uint8_t *data);
  static void SendBuffer(const uint8_t *data, size_t n);
  static void AdjustOffset(uint8_t offset);
};

#endif
