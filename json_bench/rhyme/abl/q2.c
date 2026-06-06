#include "yyjson.h"
#include "rhyme-c.h"
typedef int (*__compar_fn_t)(const void *, const void *);
struct tmp8 {
    const char **tmp8_keys_str0;
    int *tmp8_keys_len0;
    int *tmp8_htable;
    int tmp8_key_count;
    yyjson_val *tmp8__DEFAULT_;
};
struct tmp23 {
    const char **tmp23_keys_str0;
    int *tmp23_keys_len0;
    int *tmp23_htable;
    int tmp23_key_count;
    yyjson_val *tmp23__DEFAULT_;
};
int main() {
    struct timeval timeval0;
    gettimeofday(&timeval0, NULL);
    long t0 = ((timeval0.tv_sec * 1000000L) + timeval0.tv_usec);
    // init hashmap for tmp2
    // keys of tmp2
    int32_t *tmp2_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp2
    int tmp2_key_count = 0;
    // hash table for tmp2
    int *tmp2_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp2: _DEFAULT_
    int32_t *tmp2__DEFAULT_ = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    uint8_t *tmp2__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // init hashmap for tmp9
    // keys of tmp9
    int32_t *tmp9_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp9
    int tmp9_key_count = 0;
    // hash table for tmp9
    int *tmp9_htable = (int *)calloc(16777216, sizeof(int));
    struct tmp8 **tmp9__DEFAULT_ = (struct tmp8 **)malloc(sizeof(struct tmp8 *) * 16777216);
    // dynamic value of tmp8: _DEFAULT_
    // init hashmap for tmp24
    // keys of tmp24
    int32_t *tmp24_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp24
    int tmp24_key_count = 0;
    // hash table for tmp24
    int *tmp24_htable = (int *)calloc(16777216, sizeof(int));
    struct tmp23 **tmp24__DEFAULT_ = (struct tmp23 **)malloc(sizeof(struct tmp23 *) * 16777216);
    // dynamic value of tmp23: _DEFAULT_
    // init hashmap for tmp25
    // keys of tmp25
    int32_t *tmp25_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp25
    int tmp25_key_count = 0;
    // hash table for tmp25
    int *tmp25_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp25: _DEFAULT_
    double *tmp25__DEFAULT_ = (double *)malloc(sizeof(double) * 16777216);
    int fd0 = open("../data//partsupp.tbl", 0);
    if ((fd0 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//partsupp.tbl");
        return 1;
    }
    size_t n0 = fsize(fd0);
    char *file_tbl0 = mmap(0, n0, PROT_READ, MAP_FILE | MAP_SHARED, fd0, 0);
    close(fd0);
    // init array for preloaded0
    int preloaded0_data_count;
    (preloaded0_data_count = 0);
    // value of preloaded0: ps_partkey
    int32_t *preloaded0_ps_partkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // value of preloaded0: ps_suppkey
    int32_t *preloaded0_ps_suppkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // value of preloaded0: ps_supplycost
    double *preloaded0_ps_supplycost = (double *)malloc(sizeof(double) * 8000000);
    // generator: preload_iter <- loadInput('tbl', ../data//partsupp.tbl)
    size_t i0 = 0;
    for (size_t preload_iter = 0; i0 < n0; preload_iter++) {
        // reading column ps_partkey
        int32_t file_tbl0_preload_iter_ps_partkey = 0;
        int32_t tmp_negative2 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative2 = 1);
            i0++;
        }
        while ((file_tbl0[i0] != '|')) {
            // extract integer
            (file_tbl0_preload_iter_ps_partkey = ((file_tbl0_preload_iter_ps_partkey * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        i0++;
        if (tmp_negative2) {
            (file_tbl0_preload_iter_ps_partkey = -file_tbl0_preload_iter_ps_partkey);
        }
        // reading column ps_suppkey
        int32_t file_tbl0_preload_iter_ps_suppkey = 0;
        int32_t tmp_negative1 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative1 = 1);
            i0++;
        }
        while ((file_tbl0[i0] != '|')) {
            // extract integer
            (file_tbl0_preload_iter_ps_suppkey = ((file_tbl0_preload_iter_ps_suppkey * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        i0++;
        if (tmp_negative1) {
            (file_tbl0_preload_iter_ps_suppkey = -file_tbl0_preload_iter_ps_suppkey);
        }
        // reading column ps_availqty
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column ps_supplycost
        long number0 = 0;
        long scale0 = 1;
        int tmp_negative0 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative0 = 1);
            i0++;
        }
        while (((file_tbl0[i0] != '.') && (file_tbl0[i0] != '|'))) {
            // extract integer part
            (number0 = ((number0 * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        if ((file_tbl0[i0] == '.')) {
            i0++;
            while ((file_tbl0[i0] != '|')) {
                // extract fractional part
                (number0 = ((number0 * 10) + (file_tbl0[i0] - '0')));
                (scale0 = (scale0 * 10));
                i0++;
            }
        }
        double file_tbl0_preload_iter_ps_supplycost = ((double)number0 / scale0);
        i0++;
        if (tmp_negative0) {
            (file_tbl0_preload_iter_ps_supplycost = -file_tbl0_preload_iter_ps_supplycost);
        }
        // reading column ps_comment
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        i0++;
        (preloaded0_ps_partkey[preloaded0_data_count] = file_tbl0_preload_iter_ps_partkey);
        (preloaded0_ps_suppkey[preloaded0_data_count] = file_tbl0_preload_iter_ps_suppkey);
        (preloaded0_ps_supplycost[preloaded0_data_count] = file_tbl0_preload_iter_ps_supplycost);
        (preloaded0_data_count = (preloaded0_data_count + 1));
    }
    int fd1 = open("../data//region.tbl", 0);
    if ((fd1 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//region.tbl");
        return 1;
    }
    size_t n1 = fsize(fd1);
    char *file_tbl1 = mmap(0, n1, PROT_READ, MAP_FILE | MAP_SHARED, fd1, 0);
    close(fd1);
    // init array for preloaded1
    int preloaded1_data_count;
    (preloaded1_data_count = 0);
    // value of preloaded1: r_regionkey
    int32_t *preloaded1_r_regionkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // value of preloaded1: r_name
    const char **preloaded1_r_name_str = (const char **)malloc(sizeof(const char *) * 8000000);
    int *preloaded1_r_name_len = (int *)malloc(sizeof(int) * 8000000);
    // generator: preload_iter <- loadInput('tbl', ../data//region.tbl)
    size_t i1 = 0;
    for (size_t preload_iter = 0; i1 < n1; preload_iter++) {
        // reading column r_regionkey
        int32_t file_tbl1_preload_iter_r_regionkey = 0;
        int32_t tmp_negative3 = 0;
        if ((file_tbl1[i1] == '-')) {
            (tmp_negative3 = 1);
            i1++;
        }
        while ((file_tbl1[i1] != '|')) {
            // extract integer
            (file_tbl1_preload_iter_r_regionkey = ((file_tbl1_preload_iter_r_regionkey * 10) + (file_tbl1[i1] - '0')));
            i1++;
        }
        i1++;
        if (tmp_negative3) {
            (file_tbl1_preload_iter_r_regionkey = -file_tbl1_preload_iter_r_regionkey);
        }
        // reading column r_name
        size_t file_tbl1_preload_iter_r_name_start = i1;
        while ((file_tbl1[i1] != '|')) i1++;
        size_t file_tbl1_preload_iter_r_name_end = i1;
        i1++;
        // reading column r_comment
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        i1++;
        (preloaded1_r_regionkey[preloaded1_data_count] = file_tbl1_preload_iter_r_regionkey);
        (preloaded1_r_name_str[preloaded1_data_count] = (file_tbl1 + file_tbl1_preload_iter_r_name_start));
        (preloaded1_r_name_len[preloaded1_data_count] = (file_tbl1_preload_iter_r_name_end - file_tbl1_preload_iter_r_name_start));
        (preloaded1_data_count = (preloaded1_data_count + 1));
    }
    int fd2 = open("../data//nation.tbl", 0);
    if ((fd2 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//nation.tbl");
        return 1;
    }
    size_t n2 = fsize(fd2);
    char *file_tbl2 = mmap(0, n2, PROT_READ, MAP_FILE | MAP_SHARED, fd2, 0);
    close(fd2);
    // init array for preloaded2
    int preloaded2_data_count;
    (preloaded2_data_count = 0);
    // value of preloaded2: n_nationkey
    int32_t *preloaded2_n_nationkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // value of preloaded2: n_name
    const char **preloaded2_n_name_str = (const char **)malloc(sizeof(const char *) * 8000000);
    int *preloaded2_n_name_len = (int *)malloc(sizeof(int) * 8000000);
    // value of preloaded2: n_regionkey
    int32_t *preloaded2_n_regionkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // generator: preload_iter <- loadInput('tbl', ../data//nation.tbl)
    size_t i2 = 0;
    for (size_t preload_iter = 0; i2 < n2; preload_iter++) {
        // reading column n_nationkey
        int32_t file_tbl2_preload_iter_n_nationkey = 0;
        int32_t tmp_negative5 = 0;
        if ((file_tbl2[i2] == '-')) {
            (tmp_negative5 = 1);
            i2++;
        }
        while ((file_tbl2[i2] != '|')) {
            // extract integer
            (file_tbl2_preload_iter_n_nationkey = ((file_tbl2_preload_iter_n_nationkey * 10) + (file_tbl2[i2] - '0')));
            i2++;
        }
        i2++;
        if (tmp_negative5) {
            (file_tbl2_preload_iter_n_nationkey = -file_tbl2_preload_iter_n_nationkey);
        }
        // reading column n_name
        size_t file_tbl2_preload_iter_n_name_start = i2;
        while ((file_tbl2[i2] != '|')) i2++;
        size_t file_tbl2_preload_iter_n_name_end = i2;
        i2++;
        // reading column n_regionkey
        int32_t file_tbl2_preload_iter_n_regionkey = 0;
        int32_t tmp_negative4 = 0;
        if ((file_tbl2[i2] == '-')) {
            (tmp_negative4 = 1);
            i2++;
        }
        while ((file_tbl2[i2] != '|')) {
            // extract integer
            (file_tbl2_preload_iter_n_regionkey = ((file_tbl2_preload_iter_n_regionkey * 10) + (file_tbl2[i2] - '0')));
            i2++;
        }
        i2++;
        if (tmp_negative4) {
            (file_tbl2_preload_iter_n_regionkey = -file_tbl2_preload_iter_n_regionkey);
        }
        // reading column n_comment
        while ((file_tbl2[i2] != '|')) i2++;
        i2++;
        i2++;
        (preloaded2_n_nationkey[preloaded2_data_count] = file_tbl2_preload_iter_n_nationkey);
        (preloaded2_n_name_str[preloaded2_data_count] = (file_tbl2 + file_tbl2_preload_iter_n_name_start));
        (preloaded2_n_name_len[preloaded2_data_count] = (file_tbl2_preload_iter_n_name_end - file_tbl2_preload_iter_n_name_start));
        (preloaded2_n_regionkey[preloaded2_data_count] = file_tbl2_preload_iter_n_regionkey);
        (preloaded2_data_count = (preloaded2_data_count + 1));
    }
    int fd3 = open("../data//supplier.tbl", 0);
    if ((fd3 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//supplier.tbl");
        return 1;
    }
    size_t n3 = fsize(fd3);
    char *file_tbl3 = mmap(0, n3, PROT_READ, MAP_FILE | MAP_SHARED, fd3, 0);
    close(fd3);
    // init array for preloaded3
    int preloaded3_data_count;
    (preloaded3_data_count = 0);
    // value of preloaded3: s_suppkey
    int32_t *preloaded3_s_suppkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // value of preloaded3: s_name
    const char **preloaded3_s_name_str = (const char **)malloc(sizeof(const char *) * 8000000);
    int *preloaded3_s_name_len = (int *)malloc(sizeof(int) * 8000000);
    // value of preloaded3: s_address
    const char **preloaded3_s_address_str = (const char **)malloc(sizeof(const char *) * 8000000);
    int *preloaded3_s_address_len = (int *)malloc(sizeof(int) * 8000000);
    // value of preloaded3: s_nationkey
    int32_t *preloaded3_s_nationkey = (int32_t *)malloc(sizeof(int32_t) * 8000000);
    // value of preloaded3: s_phone
    const char **preloaded3_s_phone_str = (const char **)malloc(sizeof(const char *) * 8000000);
    int *preloaded3_s_phone_len = (int *)malloc(sizeof(int) * 8000000);
    // value of preloaded3: s_acctbal
    double *preloaded3_s_acctbal = (double *)malloc(sizeof(double) * 8000000);
    // value of preloaded3: s_comment
    const char **preloaded3_s_comment_str = (const char **)malloc(sizeof(const char *) * 8000000);
    int *preloaded3_s_comment_len = (int *)malloc(sizeof(int) * 8000000);
    // generator: preload_iter <- loadInput('tbl', ../data//supplier.tbl)
    size_t i3 = 0;
    for (size_t preload_iter = 0; i3 < n3; preload_iter++) {
        // reading column s_suppkey
        int32_t file_tbl3_preload_iter_s_suppkey = 0;
        int32_t tmp_negative8 = 0;
        if ((file_tbl3[i3] == '-')) {
            (tmp_negative8 = 1);
            i3++;
        }
        while ((file_tbl3[i3] != '|')) {
            // extract integer
            (file_tbl3_preload_iter_s_suppkey = ((file_tbl3_preload_iter_s_suppkey * 10) + (file_tbl3[i3] - '0')));
            i3++;
        }
        i3++;
        if (tmp_negative8) {
            (file_tbl3_preload_iter_s_suppkey = -file_tbl3_preload_iter_s_suppkey);
        }
        // reading column s_name
        size_t file_tbl3_preload_iter_s_name_start = i3;
        while ((file_tbl3[i3] != '|')) i3++;
        size_t file_tbl3_preload_iter_s_name_end = i3;
        i3++;
        // reading column s_address
        size_t file_tbl3_preload_iter_s_address_start = i3;
        while ((file_tbl3[i3] != '|')) i3++;
        size_t file_tbl3_preload_iter_s_address_end = i3;
        i3++;
        // reading column s_nationkey
        int32_t file_tbl3_preload_iter_s_nationkey = 0;
        int32_t tmp_negative7 = 0;
        if ((file_tbl3[i3] == '-')) {
            (tmp_negative7 = 1);
            i3++;
        }
        while ((file_tbl3[i3] != '|')) {
            // extract integer
            (file_tbl3_preload_iter_s_nationkey = ((file_tbl3_preload_iter_s_nationkey * 10) + (file_tbl3[i3] - '0')));
            i3++;
        }
        i3++;
        if (tmp_negative7) {
            (file_tbl3_preload_iter_s_nationkey = -file_tbl3_preload_iter_s_nationkey);
        }
        // reading column s_phone
        size_t file_tbl3_preload_iter_s_phone_start = i3;
        while ((file_tbl3[i3] != '|')) i3++;
        size_t file_tbl3_preload_iter_s_phone_end = i3;
        i3++;
        // reading column s_acctbal
        long number1 = 0;
        long scale1 = 1;
        int tmp_negative6 = 0;
        if ((file_tbl3[i3] == '-')) {
            (tmp_negative6 = 1);
            i3++;
        }
        while (((file_tbl3[i3] != '.') && (file_tbl3[i3] != '|'))) {
            // extract integer part
            (number1 = ((number1 * 10) + (file_tbl3[i3] - '0')));
            i3++;
        }
        if ((file_tbl3[i3] == '.')) {
            i3++;
            while ((file_tbl3[i3] != '|')) {
                // extract fractional part
                (number1 = ((number1 * 10) + (file_tbl3[i3] - '0')));
                (scale1 = (scale1 * 10));
                i3++;
            }
        }
        double file_tbl3_preload_iter_s_acctbal = ((double)number1 / scale1);
        i3++;
        if (tmp_negative6) {
            (file_tbl3_preload_iter_s_acctbal = -file_tbl3_preload_iter_s_acctbal);
        }
        // reading column s_comment
        size_t file_tbl3_preload_iter_s_comment_start = i3;
        while ((file_tbl3[i3] != '|')) i3++;
        size_t file_tbl3_preload_iter_s_comment_end = i3;
        i3++;
        i3++;
        (preloaded3_s_suppkey[preloaded3_data_count] = file_tbl3_preload_iter_s_suppkey);
        (preloaded3_s_name_str[preloaded3_data_count] = (file_tbl3 + file_tbl3_preload_iter_s_name_start));
        (preloaded3_s_name_len[preloaded3_data_count] = (file_tbl3_preload_iter_s_name_end - file_tbl3_preload_iter_s_name_start));
        (preloaded3_s_address_str[preloaded3_data_count] = (file_tbl3 + file_tbl3_preload_iter_s_address_start));
        (preloaded3_s_address_len[preloaded3_data_count] = (file_tbl3_preload_iter_s_address_end - file_tbl3_preload_iter_s_address_start));
        (preloaded3_s_nationkey[preloaded3_data_count] = file_tbl3_preload_iter_s_nationkey);
        (preloaded3_s_phone_str[preloaded3_data_count] = (file_tbl3 + file_tbl3_preload_iter_s_phone_start));
        (preloaded3_s_phone_len[preloaded3_data_count] = (file_tbl3_preload_iter_s_phone_end - file_tbl3_preload_iter_s_phone_start));
        (preloaded3_s_acctbal[preloaded3_data_count] = file_tbl3_preload_iter_s_acctbal);
        (preloaded3_s_comment_str[preloaded3_data_count] = (file_tbl3 + file_tbl3_preload_iter_s_comment_start));
        (preloaded3_s_comment_len[preloaded3_data_count] = (file_tbl3_preload_iter_s_comment_end - file_tbl3_preload_iter_s_comment_start));
        (preloaded3_data_count = (preloaded3_data_count + 1));
    }
    struct timeval timeval1;
    gettimeofday(&timeval1, NULL);
    long t1 = ((timeval1.tv_sec * 1000000L) + timeval1.tv_usec);
    // generator: *r1 <- loadInput('tbl', ../data//region.tbl)
    for (size_t xr1 = 0; xr1 < preloaded1_data_count; xr1++) {
        // generator: K0 <- mkset(and(equal(loadInput('tbl', ../data//region.tbl)[*r1][r_name], EUROPE), loadInput('tbl', ../data//region.tbl)[*r1][r_regionkey]))
        if (!!((preloaded1_r_name_len[xr1] == 6) ? ((*((uint64_t *)preloaded1_r_name_str[xr1]) & 0x0000FFFFFFFFFFFF) == 0x45504F525545) : 0)) {
            // singleton value here
            unsigned long hash0 = 0;
            unsigned long tmp_hash0 = (unsigned long)preloaded1_r_regionkey[xr1];
            (hash0 = (hash0 + tmp_hash0));
            unsigned long tmp_pos0$ = (hash0 & 16777215);
            while (((tmp2_htable[tmp_pos0$] != 0) && (tmp2_keys0[tmp2_htable[tmp_pos0$]] != preloaded1_r_regionkey[xr1]))) {
                (tmp_pos0$ = ((tmp_pos0$ + 1) & 16777215));
            }
            int key_pos0$ = tmp2_htable[tmp_pos0$];
            if ((key_pos0$ == 0)) {
                tmp2_key_count++;
                (key_pos0$ = tmp2_key_count);
                (tmp2_htable[tmp_pos0$] = key_pos0$);
                (tmp2_keys0[key_pos0$] = preloaded1_r_regionkey[xr1]);
            }
            if (!tmp2__DEFAULT__defined[key_pos0$]) {
                (tmp2__DEFAULT__defined[key_pos0$] = 1);
            }
            (tmp2__DEFAULT_[key_pos0$] = preloaded1_r_regionkey[xr1]);
        }
    }
    // generator: *n1 <- loadInput('tbl', ../data//nation.tbl)
    for (size_t xn1 = 0; xn1 < preloaded2_data_count; xn1++) {
        unsigned long hash1 = 0;
        unsigned long tmp_hash1 = (unsigned long)preloaded2_n_regionkey[xn1];
        (hash1 = (hash1 + tmp_hash1));
        unsigned long tmp_pos1$ = (hash1 & 16777215);
        while (((tmp2_htable[tmp_pos1$] != 0) && (tmp2_keys0[tmp2_htable[tmp_pos1$]] != preloaded2_n_regionkey[xn1]))) {
            (tmp_pos1$ = ((tmp_pos1$ + 1) & 16777215));
        }
        int key_pos1$ = tmp2_htable[tmp_pos1$];
        // generator: K4 <- mkset(and(tmp2[][loadInput('tbl', ../data//nation.tbl)[*n1][n_regionkey]], loadInput('tbl', ../data//nation.tbl)[*n1][n_nationkey]))
        if (!(key_pos1$ == 0)) {
            // singleton value here
            unsigned long hash2 = 0;
            unsigned long tmp_hash2 = (unsigned long)preloaded2_n_nationkey[xn1];
            (hash2 = (hash2 + tmp_hash2));
            unsigned long tmp_pos2$ = (hash2 & 16777215);
            while (((tmp9_htable[tmp_pos2$] != 0) && (tmp9_keys0[tmp9_htable[tmp_pos2$]] != preloaded2_n_nationkey[xn1]))) {
                (tmp_pos2$ = ((tmp_pos2$ + 1) & 16777215));
            }
            int key_pos2$ = tmp9_htable[tmp_pos2$];
            if ((key_pos2$ == 0)) {
                tmp9_key_count++;
                (key_pos2$ = tmp9_key_count);
                (tmp9_htable[tmp_pos2$] = key_pos2$);
                (tmp9_keys0[key_pos2$] = preloaded2_n_nationkey[xn1]);
                (tmp9__DEFAULT_[key_pos2$] = (struct tmp8 *)malloc(sizeof(struct tmp8) * 1));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_key_count = 0);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_htable = (int *)calloc(256, sizeof(int)));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp9__DEFAULT_[key_pos2$]->tmp8__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash3 = 0;
            unsigned long tmp_hash3 = hash("r_regionkey", 11);
            (hash3 = (hash3 + tmp_hash3));
            unsigned long tmp_pos4$ = (hash3 & 255);
            while (((tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos4$] != 0) && (compare_str2(tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0[tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos4$]], tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0[tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos4$]], "r_regionkey", 11) != 0))) {
                (tmp_pos4$ = ((tmp_pos4$ + 1) & 255));
            }
            int key_pos4$ = tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos4$];
            if ((key_pos4$ == 0)) {
                tmp9__DEFAULT_[key_pos2$]->tmp8_key_count++;
                (key_pos4$ = tmp9__DEFAULT_[key_pos2$]->tmp8_key_count);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos4$] = key_pos4$);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0[key_pos4$] = "r_regionkey");
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0[key_pos4$] = 11);
            }
            if (!(key_pos1$ == 0)) {
                yyjson_set_sint(&tmp9__DEFAULT_[key_pos2$]->tmp8__DEFAULT_[key_pos4$], tmp2__DEFAULT_[key_pos1$]);
            }
            if ((key_pos2$ == 0)) {
                tmp9_key_count++;
                (key_pos2$ = tmp9_key_count);
                (tmp9_htable[tmp_pos2$] = key_pos2$);
                (tmp9_keys0[key_pos2$] = preloaded2_n_nationkey[xn1]);
                (tmp9__DEFAULT_[key_pos2$] = (struct tmp8 *)malloc(sizeof(struct tmp8) * 1));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_key_count = 0);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_htable = (int *)calloc(256, sizeof(int)));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp9__DEFAULT_[key_pos2$]->tmp8__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash4 = 0;
            unsigned long tmp_hash4 = hash("n_nationkey", 11);
            (hash4 = (hash4 + tmp_hash4));
            unsigned long tmp_pos8$ = (hash4 & 255);
            while (((tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos8$] != 0) && (compare_str2(tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0[tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos8$]], tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0[tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos8$]], "n_nationkey", 11) != 0))) {
                (tmp_pos8$ = ((tmp_pos8$ + 1) & 255));
            }
            int key_pos8$ = tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos8$];
            if ((key_pos8$ == 0)) {
                tmp9__DEFAULT_[key_pos2$]->tmp8_key_count++;
                (key_pos8$ = tmp9__DEFAULT_[key_pos2$]->tmp8_key_count);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos8$] = key_pos8$);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0[key_pos8$] = "n_nationkey");
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0[key_pos8$] = 11);
            }
            yyjson_set_sint(&tmp9__DEFAULT_[key_pos2$]->tmp8__DEFAULT_[key_pos8$], preloaded2_n_nationkey[xn1]);
            if ((key_pos2$ == 0)) {
                tmp9_key_count++;
                (key_pos2$ = tmp9_key_count);
                (tmp9_htable[tmp_pos2$] = key_pos2$);
                (tmp9_keys0[key_pos2$] = preloaded2_n_nationkey[xn1]);
                (tmp9__DEFAULT_[key_pos2$] = (struct tmp8 *)malloc(sizeof(struct tmp8) * 1));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_key_count = 0);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_htable = (int *)calloc(256, sizeof(int)));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp9__DEFAULT_[key_pos2$]->tmp8__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash5 = 0;
            unsigned long tmp_hash5 = hash("n_name", 6);
            (hash5 = (hash5 + tmp_hash5));
            unsigned long tmp_pos11$ = (hash5 & 255);
            while (((tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos11$] != 0) && (compare_str2(tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0[tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos11$]], tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0[tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos11$]], "n_name", 6) != 0))) {
                (tmp_pos11$ = ((tmp_pos11$ + 1) & 255));
            }
            int key_pos11$ = tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos11$];
            if ((key_pos11$ == 0)) {
                tmp9__DEFAULT_[key_pos2$]->tmp8_key_count++;
                (key_pos11$ = tmp9__DEFAULT_[key_pos2$]->tmp8_key_count);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_htable[tmp_pos11$] = key_pos11$);
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_str0[key_pos11$] = "n_name");
                (tmp9__DEFAULT_[key_pos2$]->tmp8_keys_len0[key_pos11$] = 6);
            }
            yyjson_set_strn(&tmp9__DEFAULT_[key_pos2$]->tmp8__DEFAULT_[key_pos11$], preloaded2_n_name_str[xn1], preloaded2_n_name_len[xn1]);
        }
    }
    // generator: *s1 <- loadInput('tbl', ../data//supplier.tbl)
    for (size_t xs1 = 0; xs1 < preloaded3_data_count; xs1++) {
        unsigned long hash6 = 0;
        unsigned long tmp_hash6 = (unsigned long)preloaded3_s_nationkey[xs1];
        (hash6 = (hash6 + tmp_hash6));
        unsigned long tmp_pos12$ = (hash6 & 16777215);
        while (((tmp9_htable[tmp_pos12$] != 0) && (tmp9_keys0[tmp9_htable[tmp_pos12$]] != preloaded3_s_nationkey[xs1]))) {
            (tmp_pos12$ = ((tmp_pos12$ + 1) & 16777215));
        }
        int key_pos12$ = tmp9_htable[tmp_pos12$];
        // generator: K12 <- mkset(and(tmp9[][loadInput('tbl', ../data//supplier.tbl)[*s1][s_nationkey]], loadInput('tbl', ../data//supplier.tbl)[*s1][s_suppkey]))
        if (!(key_pos12$ == 0)) {
            // singleton value here
            unsigned long hash7 = 0;
            unsigned long tmp_hash7 = (unsigned long)preloaded3_s_suppkey[xs1];
            (hash7 = (hash7 + tmp_hash7));
            unsigned long tmp_pos13$ = (hash7 & 16777215);
            while (((tmp24_htable[tmp_pos13$] != 0) && (tmp24_keys0[tmp24_htable[tmp_pos13$]] != preloaded3_s_suppkey[xs1]))) {
                (tmp_pos13$ = ((tmp_pos13$ + 1) & 16777215));
            }
            int key_pos13$ = tmp24_htable[tmp_pos13$];
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash8 = 0;
            unsigned long tmp_hash8 = hash("n_name1", 7);
            (hash8 = (hash8 + tmp_hash8));
            unsigned long tmp_pos15$ = (hash8 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos15$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos15$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos15$]], "n_name1", 7) != 0))) {
                (tmp_pos15$ = ((tmp_pos15$ + 1) & 255));
            }
            int key_pos15$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos15$];
            if ((key_pos15$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos15$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos15$] = key_pos15$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos15$] = "n_name1");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos15$] = 7);
            }
            unsigned long hash9 = 0;
            unsigned long tmp_hash9 = hash("n_name", 6);
            (hash9 = (hash9 + tmp_hash9));
            unsigned long tmp_pos17$ = (hash9 & 255);
            while (((tmp9__DEFAULT_[key_pos12$]->tmp8_htable[tmp_pos17$] != 0) && (compare_str2(tmp9__DEFAULT_[key_pos12$]->tmp8_keys_str0[tmp9__DEFAULT_[key_pos12$]->tmp8_htable[tmp_pos17$]], tmp9__DEFAULT_[key_pos12$]->tmp8_keys_len0[tmp9__DEFAULT_[key_pos12$]->tmp8_htable[tmp_pos17$]], "n_name", 6) != 0))) {
                (tmp_pos17$ = ((tmp_pos17$ + 1) & 255));
            }
            int key_pos17$ = tmp9__DEFAULT_[key_pos12$]->tmp8_htable[tmp_pos17$];
            if (!(key_pos17$ == 0)) {
                (*&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos15$] = *&tmp9__DEFAULT_[key_pos12$]->tmp8__DEFAULT_[key_pos17$]);
            }
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash10 = 0;
            unsigned long tmp_hash10 = hash("s_suppkey", 9);
            (hash10 = (hash10 + tmp_hash10));
            unsigned long tmp_pos20$ = (hash10 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos20$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos20$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos20$]], "s_suppkey", 9) != 0))) {
                (tmp_pos20$ = ((tmp_pos20$ + 1) & 255));
            }
            int key_pos20$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos20$];
            if ((key_pos20$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos20$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos20$] = key_pos20$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos20$] = "s_suppkey");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos20$] = 9);
            }
            yyjson_set_sint(&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos20$], preloaded3_s_suppkey[xs1]);
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash11 = 0;
            unsigned long tmp_hash11 = hash("s_name", 6);
            (hash11 = (hash11 + tmp_hash11));
            unsigned long tmp_pos23$ = (hash11 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos23$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos23$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos23$]], "s_name", 6) != 0))) {
                (tmp_pos23$ = ((tmp_pos23$ + 1) & 255));
            }
            int key_pos23$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos23$];
            if ((key_pos23$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos23$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos23$] = key_pos23$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos23$] = "s_name");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos23$] = 6);
            }
            yyjson_set_strn(&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos23$], preloaded3_s_name_str[xs1], preloaded3_s_name_len[xs1]);
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash12 = 0;
            unsigned long tmp_hash12 = hash("s_address", 9);
            (hash12 = (hash12 + tmp_hash12));
            unsigned long tmp_pos26$ = (hash12 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos26$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos26$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos26$]], "s_address", 9) != 0))) {
                (tmp_pos26$ = ((tmp_pos26$ + 1) & 255));
            }
            int key_pos26$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos26$];
            if ((key_pos26$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos26$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos26$] = key_pos26$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos26$] = "s_address");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos26$] = 9);
            }
            yyjson_set_strn(&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos26$], preloaded3_s_address_str[xs1], preloaded3_s_address_len[xs1]);
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash13 = 0;
            unsigned long tmp_hash13 = hash("s_phone", 7);
            (hash13 = (hash13 + tmp_hash13));
            unsigned long tmp_pos29$ = (hash13 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos29$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos29$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos29$]], "s_phone", 7) != 0))) {
                (tmp_pos29$ = ((tmp_pos29$ + 1) & 255));
            }
            int key_pos29$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos29$];
            if ((key_pos29$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos29$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos29$] = key_pos29$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos29$] = "s_phone");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos29$] = 7);
            }
            yyjson_set_strn(&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos29$], preloaded3_s_phone_str[xs1], preloaded3_s_phone_len[xs1]);
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash14 = 0;
            unsigned long tmp_hash14 = hash("s_acctbal", 9);
            (hash14 = (hash14 + tmp_hash14));
            unsigned long tmp_pos32$ = (hash14 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos32$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos32$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos32$]], "s_acctbal", 9) != 0))) {
                (tmp_pos32$ = ((tmp_pos32$ + 1) & 255));
            }
            int key_pos32$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos32$];
            if ((key_pos32$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos32$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos32$] = key_pos32$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos32$] = "s_acctbal");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos32$] = 9);
            }
            yyjson_set_real(&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos32$], preloaded3_s_acctbal[xs1]);
            if ((key_pos13$ == 0)) {
                tmp24_key_count++;
                (key_pos13$ = tmp24_key_count);
                (tmp24_htable[tmp_pos13$] = key_pos13$);
                (tmp24_keys0[key_pos13$] = preloaded3_s_suppkey[xs1]);
                (tmp24__DEFAULT_[key_pos13$] = (struct tmp23 *)malloc(sizeof(struct tmp23) * 1));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_key_count = 0);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable = (int *)calloc(256, sizeof(int)));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash15 = 0;
            unsigned long tmp_hash15 = hash("s_comment", 9);
            (hash15 = (hash15 + tmp_hash15));
            unsigned long tmp_pos35$ = (hash15 & 255);
            while (((tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos35$] != 0) && (compare_str2(tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos35$]], tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos35$]], "s_comment", 9) != 0))) {
                (tmp_pos35$ = ((tmp_pos35$ + 1) & 255));
            }
            int key_pos35$ = tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos35$];
            if ((key_pos35$ == 0)) {
                tmp24__DEFAULT_[key_pos13$]->tmp23_key_count++;
                (key_pos35$ = tmp24__DEFAULT_[key_pos13$]->tmp23_key_count);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_htable[tmp_pos35$] = key_pos35$);
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_str0[key_pos35$] = "s_comment");
                (tmp24__DEFAULT_[key_pos13$]->tmp23_keys_len0[key_pos35$] = 9);
            }
            yyjson_set_strn(&tmp24__DEFAULT_[key_pos13$]->tmp23__DEFAULT_[key_pos35$], preloaded3_s_comment_str[xs1], preloaded3_s_comment_len[xs1]);
        }
    }
    // generator: *ps1 <- loadInput('tbl', ../data//partsupp.tbl)
    for (size_t xps1 = 0; xps1 < preloaded0_data_count; xps1++) {
        unsigned long hash16 = 0;
        unsigned long tmp_hash16 = (unsigned long)preloaded0_ps_suppkey[xps1];
        (hash16 = (hash16 + tmp_hash16));
        unsigned long tmp_pos36$ = (hash16 & 16777215);
        while (((tmp24_htable[tmp_pos36$] != 0) && (tmp24_keys0[tmp24_htable[tmp_pos36$]] != preloaded0_ps_suppkey[xps1]))) {
            (tmp_pos36$ = ((tmp_pos36$ + 1) & 16777215));
        }
        int key_pos36$ = tmp24_htable[tmp_pos36$];
        // generator: K13 <- mkset(and(tmp24[][loadInput('tbl', ../data//partsupp.tbl)[*ps1][ps_suppkey]], loadInput('tbl', ../data//partsupp.tbl)[*ps1][ps_partkey]))
        if (!(key_pos36$ == 0)) {
            // singleton value here
            unsigned long hash17 = 0;
            unsigned long tmp_hash17 = (unsigned long)preloaded0_ps_partkey[xps1];
            (hash17 = (hash17 + tmp_hash17));
            unsigned long tmp_pos37$ = (hash17 & 16777215);
            while (((tmp25_htable[tmp_pos37$] != 0) && (tmp25_keys0[tmp25_htable[tmp_pos37$]] != preloaded0_ps_partkey[xps1]))) {
                (tmp_pos37$ = ((tmp_pos37$ + 1) & 16777215));
            }
            int key_pos37$ = tmp25_htable[tmp_pos37$];
            if ((key_pos37$ == 0)) {
                tmp25_key_count++;
                (key_pos37$ = tmp25_key_count);
                (tmp25_htable[tmp_pos37$] = key_pos37$);
                (tmp25_keys0[key_pos37$] = preloaded0_ps_partkey[xps1]);
                (tmp25__DEFAULT_[key_pos37$] = 1.7976931348623157e+308);
            }
            tmp25__DEFAULT_[key_pos37$] = preloaded0_ps_supplycost[xps1] < tmp25__DEFAULT_[key_pos37$] ? preloaded0_ps_supplycost[xps1] : tmp25__DEFAULT_[key_pos37$];
        }
    }
    // print hashmap
    printf("{");
    for (int i = 0; i < tmp25_key_count; i++) {
        int key_pos = i + 1;
        // print key
        printf("\"%d\"", tmp25_keys0[key_pos]);
        printf(":");
        // print value
        if ((key_pos == 0)) {
            printf("null");
        } else {
            printf("%.4lf", tmp25__DEFAULT_[key_pos]);
        }
        if (i != tmp25_key_count - 1) {
            printf(",");
        }
    }
    printf("}");
    fflush(stdout);
    struct timeval timeval2;
    gettimeofday(&timeval2, NULL);
    long t2 = ((timeval2.tv_sec * 1000000L) + timeval2.tv_usec);
    fprintf(stderr, "\n\nTiming:\n\tInitializaton:\t%ld μs\n\tRuntime:\t%ld μs\n\tTotal:\t\t%ld μs\n", (t1 - t0), (t2 - t1), (t2 - t0));
    return 0;
}
