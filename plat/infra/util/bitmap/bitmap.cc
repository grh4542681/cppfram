#include <string>
#include "bitmap.h"

namespace util::bitmap {

Bitmap::Bitmap() { }

Bitmap::Bitmap(size_t bit_size)
{
    bit_max_size_ = bit_size;
    bit_cur_size_ = 0;
    page_num_ = (bit_size + (BITMAP_PAGESIZE-1)) / BITMAP_PAGESIZE;
    page_head_ = mempool_->Malloc(page_num_ * BITMAP_PAGESIZE);
    if (page_head_) {
        free_flag_ = true;
    }
}

Bitmap::Bitmap(size_t bit_size, void* bit_head)
{
    bit_max_size_ = bit_size;
    bit_cur_size_ = 0;
    page_num_ = (bit_size + (BITMAP_PAGESIZE-1)) / BITMAP_PAGESIZE;
    if (bit_head) {
        page_head_ = bit_head;
        free_flag_ = false;
    } else {
        page_head_ = mempool_->Malloc(page_num_ * BITMAP_PAGESIZE);
        if (page_head_) {
            free_flag_ = true;
        }
    }

    size_t loop_page = 0;
    size_t loop_page_bit = 0;
    size_t tmp_max_bit = bit_max_size_;
    char* tmp = reinterpret_cast<char*>(page_head_);

    for (loop_page = 0; loop_page < page_num_; loop_page++) {
        for (loop_page_bit = 0; loop_page_bit < BITMAP_PAGESIZE; loop_page_bit++, tmp_max_bit--) {
            if (tmp_max_bit == 0) {
                break;
            }
            tmp[loop_page] & (1 << loop_page_bit) ? bit_cur_size_++ : bit_cur_size_;
        }
        if (tmp_max_bit == 0) {
            break;
        }
    }
}

Bitmap::Bitmap(Bitmap& other)
{

}

Bitmap::~Bitmap()
{
    if (free_flag_) {
        mempool_->Free(page_head_);
    }
}

size_t Bitmap::GetCurBitsize()
{
    return bit_cur_size_;
}

size_t Bitmap::GetMaxBitsize()
{
    return bit_max_size_;
}

BitmapRet Bitmap::Set(size_t index)
{
    if (!page_head_) {
        return BitmapRet::EINIT;
    }
    if (index == 0 || index > bit_max_size_) {
        return BitmapRet::BM_EOUTBOUND;
    }
    size_t page_index = (index + BITMAP_PAGESIZE - 1) / BITMAP_PAGESIZE;
    size_t page_offset = (index - 1 ) % BITMAP_PAGESIZE;
    char* tmp = reinterpret_cast<char*>(page_head_);
    tmp[page_index - 1] = tmp[page_index - 1] | (1 << page_offset);
    bit_cur_size_++;
    return BitmapRet::SUCCESS;
}

BitmapRet Bitmap::Unset(size_t index)
{
    if (!page_head_) {
        return BitmapRet::EINIT;
    }
    if (index == 0 || index > bit_max_size_) {
        return BitmapRet::BM_EOUTBOUND;
    }
    size_t page_index = (index + BITMAP_PAGESIZE - 1) / BITMAP_PAGESIZE;
    size_t page_offset = (index - 1 ) % BITMAP_PAGESIZE;
    char* tmp = reinterpret_cast<char*>(page_head_);
    tmp[page_index - 1] = tmp[page_index - 1] &~ (1 << page_offset);
    bit_cur_size_--;
    return BitmapRet::SUCCESS;
}

void Bitmap::Print1()
{
    size_t page_index = 0;
    size_t page_offset = 0;
    size_t tmp_max_bit = bit_max_size_;
    char* tmp = reinterpret_cast<char*>(page_head_);
    for (page_index = 0; page_index < page_num_; page_index++) {
        for (page_offset = 0; page_offset < BITMAP_PAGESIZE; page_offset++, tmp_max_bit--) {
            if (tmp_max_bit == 0) {
                break;
            }
            if ((tmp[page_index] & (1 << page_offset)) != 0) {
                printf("%lu ", (page_index * BITMAP_PAGESIZE + page_offset + 1));
            }
        }
        if (tmp_max_bit == 0) {
            break;
        }
    }
    printf("\n");
}

void Bitmap::Print0()
{
    size_t page_index = 0;
    size_t page_offset = 0;
    size_t tmp_max_bit = bit_max_size_;
    char* tmp = reinterpret_cast<char*>(page_head_);
    for (page_index = 0; page_index < page_num_; page_index++) {
        for (page_offset = 0; page_offset < BITMAP_PAGESIZE; page_offset++, tmp_max_bit--) {
            if (tmp_max_bit == 0) {
                break;
            }
            if ((tmp[page_index] & (1 << page_offset)) == 0) {
                printf("%lu ", (page_index * BITMAP_PAGESIZE + page_offset + 1));
            }
        }
        if (tmp_max_bit == 0) {
            break;
        }
    }
    printf("\n");
}

size_t Bitmap::Find1()
{
    size_t page_index = 0;
    size_t page_offset = 0;
    size_t tmp_max_bit = bit_max_size_;
    char* tmp = reinterpret_cast<char*>(page_head_);
    for (page_index = 0; page_index < page_num_; page_index++) {
        for (page_offset = 0; page_offset < BITMAP_PAGESIZE; page_offset++, tmp_max_bit--) {
            if (tmp_max_bit == 0) {
                break;
            }
            if ((tmp[page_index] & (1 << page_offset)) != 0) {
                return (page_index * BITMAP_PAGESIZE + page_offset + 1) ;
            }
        }
        if (tmp_max_bit == 0) {
            break;
        }
    }
    return 0;
}

size_t Bitmap::Find0()
{
    size_t page_index = 0;
    size_t page_offset = 0;
    size_t tmp_max_bit = bit_max_size_;
    char* tmp = reinterpret_cast<char*>(page_head_);
    for (page_index = 0; page_index < page_num_; page_index++) {
        for (page_offset = 0; page_offset < BITMAP_PAGESIZE; page_offset++, tmp_max_bit--) {
            if (tmp_max_bit == 0) {
                break;
            }
            if ((tmp[page_index] & (1 << page_offset)) == 0) {
                return (page_index * BITMAP_PAGESIZE + page_offset + 1) ;
            }
        }
        if (tmp_max_bit == 0) {
            break;
        }
    }
    return 0;
}

bool Bitmap::IsFull()
{
    return bit_max_size_ == bit_cur_size_;
}

void Bitmap::Print()
{
    std::string str;
    size_t page_index = 0;
    size_t page_offset = 0;
    size_t tmp_max_bit = bit_max_size_;
    char* tmp = reinterpret_cast<char*>(page_head_);
    for (page_index = 0; page_index < page_num_; page_index++) {
        for (page_offset = 0; page_offset < BITMAP_PAGESIZE; page_offset++, tmp_max_bit--) {
            if (tmp_max_bit == 0) {
                break;
            }
            if ((tmp[page_index] & (1 << page_offset)) != 0) {
                str += "1";
            } else {
                str += "0";
            }
        }
        if (tmp_max_bit == 0) {
            break;
        }
    }
    printf("%s\n", std::string(str.rbegin(), str.rend()).c_str());
}

}
