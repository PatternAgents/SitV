// Copyright (c) 2016 Patrick Dowling
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef PAGE_DISPLAY_DRIVER_H_
#define PAGE_DISPLAY_DRIVER_H_

#include "../util/util_macros.h"

// Basic driver that can send parts of frame buffer (pages) to driver device.
// In theory parts of the transfer may be done via DMA and the page memory
// will have to be valid until that completes, so the ::Flush call is used
// to determine if cleanup is necessary.
template <typename display_driver>
class PagedDisplayDriver {
public:

  PagedDisplayDriver() { }

  void Init() {

    display_driver::Init();

    current_page_index_ = 0;
    current_page_data_ = NULL;
  }

  void Begin(const uint8_t *frame) {
    current_page_data_ = frame;
    current_page_index_ = 0;
  }

  void Update() {
    uint_fast8_t page = current_page_index_;
    if (page < display_driver::kNumPages) {
      const uint8_t *data = current_page_data_;
      display_driver::SendPage(page, data);
      current_page_index_ = page + 1;
      current_page_data_ = data + display_driver::kPageSize;
    }
  }

  bool Flush() {
    display_driver::Flush();
    if (current_page_index_ < display_driver::kNumPages) {
      return false;
    } else {
      current_page_index_ = 0;
      current_page_data_ = NULL;
      return true;
    }
  }

  bool frame_valid() const {
    return NULL != current_page_data_;
  }

private:
  uint_fast8_t current_page_index_;
  const uint8_t *current_page_data_;

  DISALLOW_COPY_AND_ASSIGN(PagedDisplayDriver);
};

#endif // PAGE_DISPLAY_DRIVER_H_
