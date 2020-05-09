#ifndef  COMMON_H_X85R
#define COMMON_H_X85R

//#define SAMPLE_RATE 				16000
//#define CODE_DURATION 		4 // x

#define MAX_SAMPLE_VALUE  (32767 * 7 / 10) //modify this will affect ENEGY_THRESHOLD
//#define FFT_BITS						8
//#define FFT_WIN              	        (1<<FFT_BITS)
//#define MIN_FREQ_ABOUT      3000

//#define BASE_FREQ      				((SAMPLE_RATE *  (MIN_FREQ_ABOUT * FFT_WIN / SAMPLE_RATE)) / FFT_WIN)
//#define BASE_FREQ_INDEX       (BASE_FREQ * FFT_WIN / SAMPLE_RATE)

//#define FREQ_RESOLUTION     2 			//3x
//#define ENEGY_THRESHOLD    1024 //TODO
#ifdef USE_DB_ENEGER
//#define ENEGY_THRESHOLD    		-30
#else

#endif
//#define FREQ_STEP						(SAMPLE_RATE*/FFT_WIN)

//[~8K - 12K]  step 220.5
#define CODE_BOOK_SIZE       18
#define CODE_BOOK_ESCAPE  2 //count
#define CODE_0						    CODE_BOOK_ESCAPE
#define CODE_ESCAPE_SYNC   0 //(CODE_BOOK_SIZE-2)
#define CODE_ESCAPE_SPLIT	1 //(CODE_BOOK_SIZE-1)
#define CODE_INVALID				-1
//#define CODE_SAMPLES 		    (FFT_WIN*CODE_DURATION) //about 58ms

#define MAX_CODE_LENGTH	64

//#define INT_MAX       					2147483647
//#define INT_MIN       					(-INT_MAX-1)
#define MAX(a,b) 						((a)>(b) ? (a) : (b))

#define IS_NORMAL_CODE(c)  (c >=CODE_BOOK_ESCAPE && c<CODE_BOOK_SIZE ? 1 : 0)
#define IS_VALIDE_CODE(c)     (c >=0 && c<CODE_BOOK_SIZE ? 1 : 0)
#define IS_SYNC_CODE(c)  		(c == CODE_ESCAPE_SYNC)
#define IS_SPLIT_CODE(c)  		(c == CODE_ESCAPE_SPLIT)

typedef struct codec_para_s {
    
	int sample_rate_sender;
	int sample_rate_receiver;
	int fft_bits;
	int fft_win;
	int code_duration;
	int code_samples;
	int base_freq;
	int base_freq_index;
	int min_freq_about;
	int freq_resolution;
	int enegy_threshold;
    
} codec_para_t;

int parameter_calc(codec_para_t *para);
#endif
