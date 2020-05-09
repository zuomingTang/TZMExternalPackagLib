#ifndef  encode_H_EXJHX
#define encode_H_EXJHX

#ifdef __cplusplus
extern "C" {
#endif
    
#include"common.h"
    
    typedef struct encode_context {
        short *tab_code[CODE_BOOK_SIZE];  //about 90kbyte
        codec_para_t codec_para;
    } encode_context_t;
    
    encode_context_t *encode_init(int sample_rate_sender, int sample_rate_receiver, int min_freq_about,int freq_resolution);
    void encode_close(encode_context_t *context);
    short *encode_get_codebuffer(encode_context_t *context, int code);
    int encode_string(const char *data, int datalen, char *out_data);
    
#ifdef __cplusplus
}
#endif
#endif
