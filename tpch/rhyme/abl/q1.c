#include "yyjson.h"
#include "rhyme-c.h"
typedef int (*__compar_fn_t)(const void *, const void *);
struct tmp21 {
    const char **tmp21_keys_str0;
    int *tmp21_keys_len0;
    int *tmp21_htable;
    int tmp21_key_count;
    yyjson_val *tmp21__DEFAULT_;
};
int main() {
    struct timeval timeval0;
    gettimeofday(&timeval0, NULL);
    long t0 = ((timeval0.tv_sec * 1000000L) + timeval0.tv_usec);
    // init hashmap for tmp22
    // keys of tmp22
    char *tmp22_keys0 = (char *)malloc(sizeof(char) * 8);
    char *tmp22_keys1 = (char *)malloc(sizeof(char) * 8);
    // key count for tmp22
    int tmp22_key_count = 0;
    // hash table for tmp22
    int *tmp22_htable = (int *)calloc(8, sizeof(int));
    struct tmp21 **tmp22__DEFAULT_ = (struct tmp21 **)malloc(sizeof(struct tmp21 *) * 8);
    // dynamic value of tmp21: _DEFAULT_
    char tmp0;
    uint8_t tmp0_defined = 0;
    char tmp2;
    uint8_t tmp2_defined = 0;
    double tmp4;
    uint8_t tmp4_defined = 0;
    double tmp6;
    uint8_t tmp6_defined = 0;
    double tmp8;
    uint8_t tmp8_defined = 0;
    double tmp10;
    uint8_t tmp10_defined = 0;
    uint32_t tmp12;
    uint8_t tmp12_defined = 0;
    uint32_t tmp14;
    uint8_t tmp14_defined = 0;
    double tmp16;
    uint8_t tmp16_defined = 0;
    uint32_t tmp18;
    uint8_t tmp18_defined = 0;
    uint32_t tmp20;
    uint8_t tmp20_defined = 0;
    int fd0 = open("../data//lineitem.tbl", 0);
    if ((fd0 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//lineitem.tbl");
        return 1;
    }
    size_t n0 = fsize(fd0);
    char *file_tbl0 = mmap(0, n0, PROT_READ, MAP_FILE | MAP_SHARED, fd0, 0);
    close(fd0);
    // init array for preloaded0
    int preloaded0_data_count;
    (preloaded0_data_count = 0);
    // value of preloaded0: l_quantity
    double *preloaded0_l_quantity = (double *)malloc(sizeof(double) * 60000000);
    // value of preloaded0: l_extendedprice
    double *preloaded0_l_extendedprice = (double *)malloc(sizeof(double) * 60000000);
    // value of preloaded0: l_discount
    double *preloaded0_l_discount = (double *)malloc(sizeof(double) * 60000000);
    // value of preloaded0: l_tax
    double *preloaded0_l_tax = (double *)malloc(sizeof(double) * 60000000);
    // value of preloaded0: l_returnflag
    char *preloaded0_l_returnflag = (char *)malloc(sizeof(char) * 60000000);
    // value of preloaded0: l_linestatus
    char *preloaded0_l_linestatus = (char *)malloc(sizeof(char) * 60000000);
    // value of preloaded0: l_shipdate
    int32_t *preloaded0_l_shipdate = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//lineitem.tbl)
    size_t i0 = 0;
    for (size_t preload_iter = 0; i0 < n0; preload_iter++) {
        // reading column l_orderkey
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_partkey
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_suppkey
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_linenumber
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_quantity
        long number3 = 0;
        long scale3 = 1;
        int tmp_negative3 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative3 = 1);
            i0++;
        }
        while (((file_tbl0[i0] != '.') && (file_tbl0[i0] != '|'))) {
            // extract integer part
            (number3 = ((number3 * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        if ((file_tbl0[i0] == '.')) {
            i0++;
            while ((file_tbl0[i0] != '|')) {
                // extract fractional part
                (number3 = ((number3 * 10) + (file_tbl0[i0] - '0')));
                (scale3 = (scale3 * 10));
                i0++;
            }
        }
        double file_tbl0_preload_iter_l_quantity = ((double)number3 / scale3);
        i0++;
        if (tmp_negative3) {
            (file_tbl0_preload_iter_l_quantity = -file_tbl0_preload_iter_l_quantity);
        }
        // reading column l_extendedprice
        long number2 = 0;
        long scale2 = 1;
        int tmp_negative2 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative2 = 1);
            i0++;
        }
        while (((file_tbl0[i0] != '.') && (file_tbl0[i0] != '|'))) {
            // extract integer part
            (number2 = ((number2 * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        if ((file_tbl0[i0] == '.')) {
            i0++;
            while ((file_tbl0[i0] != '|')) {
                // extract fractional part
                (number2 = ((number2 * 10) + (file_tbl0[i0] - '0')));
                (scale2 = (scale2 * 10));
                i0++;
            }
        }
        double file_tbl0_preload_iter_l_extendedprice = ((double)number2 / scale2);
        i0++;
        if (tmp_negative2) {
            (file_tbl0_preload_iter_l_extendedprice = -file_tbl0_preload_iter_l_extendedprice);
        }
        // reading column l_discount
        long number1 = 0;
        long scale1 = 1;
        int tmp_negative1 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative1 = 1);
            i0++;
        }
        while (((file_tbl0[i0] != '.') && (file_tbl0[i0] != '|'))) {
            // extract integer part
            (number1 = ((number1 * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        if ((file_tbl0[i0] == '.')) {
            i0++;
            while ((file_tbl0[i0] != '|')) {
                // extract fractional part
                (number1 = ((number1 * 10) + (file_tbl0[i0] - '0')));
                (scale1 = (scale1 * 10));
                i0++;
            }
        }
        double file_tbl0_preload_iter_l_discount = ((double)number1 / scale1);
        i0++;
        if (tmp_negative1) {
            (file_tbl0_preload_iter_l_discount = -file_tbl0_preload_iter_l_discount);
        }
        // reading column l_tax
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
        double file_tbl0_preload_iter_l_tax = ((double)number0 / scale0);
        i0++;
        if (tmp_negative0) {
            (file_tbl0_preload_iter_l_tax = -file_tbl0_preload_iter_l_tax);
        }
        // reading column l_returnflag
        char file_tbl0_preload_iter_l_returnflag = file_tbl0[i0];
        (i0 = (i0 + 2));
        // reading column l_linestatus
        char file_tbl0_preload_iter_l_linestatus = file_tbl0[i0];
        (i0 = (i0 + 2));
        // reading column l_shipdate
        int32_t file_tbl0_preload_iter_l_shipdate = (((((((file_tbl0[i0] * 10 + file_tbl0[i0 + 1]) * 10 + file_tbl0[i0 + 2]) * 10 + file_tbl0[i0 + 3]) * 10 + file_tbl0[i0 + 5]) * 10 + file_tbl0[i0 + 6]) * 10 + file_tbl0[i0 + 8]) * 10 + file_tbl0[i0 + 9]) - 533333328;
        (i0 = (i0 + 11));
        // reading column l_commitdate
        (i0 = (i0 + 11));
        // reading column l_receiptdate
        (i0 = (i0 + 11));
        // reading column l_shipinstruct
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_shipmode
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_comment
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        i0++;
        (preloaded0_l_quantity[preloaded0_data_count] = file_tbl0_preload_iter_l_quantity);
        (preloaded0_l_extendedprice[preloaded0_data_count] = file_tbl0_preload_iter_l_extendedprice);
        (preloaded0_l_discount[preloaded0_data_count] = file_tbl0_preload_iter_l_discount);
        (preloaded0_l_tax[preloaded0_data_count] = file_tbl0_preload_iter_l_tax);
        (preloaded0_l_returnflag[preloaded0_data_count] = file_tbl0_preload_iter_l_returnflag);
        (preloaded0_l_linestatus[preloaded0_data_count] = file_tbl0_preload_iter_l_linestatus);
        (preloaded0_l_shipdate[preloaded0_data_count] = file_tbl0_preload_iter_l_shipdate);
        (preloaded0_data_count = (preloaded0_data_count + 1));
    }
    struct timeval timeval1;
    gettimeofday(&timeval1, NULL);
    long t1 = ((timeval1.tv_sec * 1000000L) + timeval1.tv_usec);
    // generator: D0 <- loadInput('tbl', ../data//lineitem.tbl)
    for (size_t D0 = 0; D0 < preloaded0_data_count; D0++) {
        // generator: K12 <- mkset(combine(and(lessThanOrEqual(loadInput('tbl', ../data//lineitem.tbl)[D0][l_shipdate], 19980902), loadInput('tbl', ../data//lineitem.tbl)[D0][l_returnflag]), loadInput('tbl', ../data//lineitem.tbl)[D0][l_linestatus]))
        if (!!(preloaded0_l_shipdate[D0] <= 19980902)) {
            // singleton value here
            unsigned long hash0 = 0;
            unsigned long tmp_hash0 = (unsigned long)preloaded0_l_returnflag[D0];
            (hash0 = (hash0 + tmp_hash0));
            unsigned long tmp_hash1 = (unsigned long)preloaded0_l_linestatus[D0];
            (hash0 = (hash0 * 31));
            (hash0 = (hash0 + tmp_hash1));
            unsigned long tmp_pos0$ = (hash0 & 7);
            while (((tmp22_htable[tmp_pos0$] != 0) && ((tmp22_keys0[tmp22_htable[tmp_pos0$]] != preloaded0_l_returnflag[D0]) || (tmp22_keys1[tmp22_htable[tmp_pos0$]] != preloaded0_l_linestatus[D0])))) {
                (tmp_pos0$ = ((tmp_pos0$ + 1) & 7));
            }
            int key_pos0$ = tmp22_htable[tmp_pos0$];
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash1 = 0;
            unsigned long tmp_hash2 = hash("l_returnflag", 12);
            (hash1 = (hash1 + tmp_hash2));
            unsigned long tmp_pos2$ = (hash1 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos2$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos2$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos2$]], "l_returnflag", 12) != 0))) {
                (tmp_pos2$ = ((tmp_pos2$ + 1) & 255));
            }
            int key_pos2$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos2$];
            if ((key_pos2$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos2$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos2$] = key_pos2$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos2$] = "l_returnflag");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos2$] = 12);
            }
            yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos2$], preloaded0_l_returnflag[D0]);
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash2 = 0;
            unsigned long tmp_hash3 = hash("l_linestatus", 12);
            (hash2 = (hash2 + tmp_hash3));
            unsigned long tmp_pos5$ = (hash2 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos5$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos5$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos5$]], "l_linestatus", 12) != 0))) {
                (tmp_pos5$ = ((tmp_pos5$ + 1) & 255));
            }
            int key_pos5$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos5$];
            if ((key_pos5$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos5$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos5$] = key_pos5$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos5$] = "l_linestatus");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos5$] = 12);
            }
            yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos5$], preloaded0_l_linestatus[D0]);
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash3 = 0;
            unsigned long tmp_hash4 = hash("sum_qty", 7);
            (hash3 = (hash3 + tmp_hash4));
            unsigned long tmp_pos8$ = (hash3 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos8$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos8$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos8$]], "sum_qty", 7) != 0))) {
                (tmp_pos8$ = ((tmp_pos8$ + 1) & 255));
            }
            int key_pos8$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos8$];
            if ((key_pos8$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos8$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos8$] = key_pos8$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos8$] = "sum_qty");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos8$] = 7);
                yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos8$], 0);
            }
            yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos8$], (yyjson_get_num(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos8$]) + preloaded0_l_quantity[D0]));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash4 = 0;
            unsigned long tmp_hash5 = hash("sum_base_price", 14);
            (hash4 = (hash4 + tmp_hash5));
            unsigned long tmp_pos13$ = (hash4 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos13$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos13$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos13$]], "sum_base_price", 14) != 0))) {
                (tmp_pos13$ = ((tmp_pos13$ + 1) & 255));
            }
            int key_pos13$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos13$];
            if ((key_pos13$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos13$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos13$] = key_pos13$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos13$] = "sum_base_price");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos13$] = 14);
                yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos13$], 0);
            }
            yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos13$], (yyjson_get_num(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos13$]) + preloaded0_l_extendedprice[D0]));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash5 = 0;
            unsigned long tmp_hash6 = hash("sum_disc_price", 14);
            (hash5 = (hash5 + tmp_hash6));
            unsigned long tmp_pos18$ = (hash5 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos18$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos18$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos18$]], "sum_disc_price", 14) != 0))) {
                (tmp_pos18$ = ((tmp_pos18$ + 1) & 255));
            }
            int key_pos18$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos18$];
            if ((key_pos18$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos18$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos18$] = key_pos18$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos18$] = "sum_disc_price");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos18$] = 14);
                yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos18$], 0);
            }
            yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos18$], (yyjson_get_num(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos18$]) + (double)(preloaded0_l_extendedprice[D0] * (double)(1 - preloaded0_l_discount[D0]))));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash6 = 0;
            unsigned long tmp_hash7 = hash("sum_charge", 10);
            (hash6 = (hash6 + tmp_hash7));
            unsigned long tmp_pos23$ = (hash6 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos23$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos23$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos23$]], "sum_charge", 10) != 0))) {
                (tmp_pos23$ = ((tmp_pos23$ + 1) & 255));
            }
            int key_pos23$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos23$];
            if ((key_pos23$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos23$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos23$] = key_pos23$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos23$] = "sum_charge");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos23$] = 10);
                yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos23$], 0);
            }
            yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos23$], (yyjson_get_num(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos23$]) + (double)((double)(preloaded0_l_extendedprice[D0] * (double)(1 - preloaded0_l_discount[D0])) * (double)(1 + preloaded0_l_tax[D0]))));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash7 = 0;
            unsigned long tmp_hash8 = hash("count_l_quantity", 16);
            (hash7 = (hash7 + tmp_hash8));
            unsigned long tmp_pos28$ = (hash7 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos28$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos28$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos28$]], "count_l_quantity", 16) != 0))) {
                (tmp_pos28$ = ((tmp_pos28$ + 1) & 255));
            }
            int key_pos28$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos28$];
            if ((key_pos28$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos28$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos28$] = key_pos28$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos28$] = "count_l_quantity");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos28$] = 16);
                yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos28$], 0);
            }
            yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos28$], (yyjson_get_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos28$]) + 1));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash8 = 0;
            unsigned long tmp_hash9 = hash("count_l_extendedprice", 21);
            (hash8 = (hash8 + tmp_hash9));
            unsigned long tmp_pos33$ = (hash8 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos33$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos33$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos33$]], "count_l_extendedprice", 21) != 0))) {
                (tmp_pos33$ = ((tmp_pos33$ + 1) & 255));
            }
            int key_pos33$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos33$];
            if ((key_pos33$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos33$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos33$] = key_pos33$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos33$] = "count_l_extendedprice");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos33$] = 21);
                yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos33$], 0);
            }
            yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos33$], (yyjson_get_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos33$]) + 1));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash9 = 0;
            unsigned long tmp_hash10 = hash("sum_l_discount", 14);
            (hash9 = (hash9 + tmp_hash10));
            unsigned long tmp_pos38$ = (hash9 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos38$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos38$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos38$]], "sum_l_discount", 14) != 0))) {
                (tmp_pos38$ = ((tmp_pos38$ + 1) & 255));
            }
            int key_pos38$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos38$];
            if ((key_pos38$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos38$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos38$] = key_pos38$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos38$] = "sum_l_discount");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos38$] = 14);
                yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos38$], 0);
            }
            yyjson_set_real(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos38$], (yyjson_get_num(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos38$]) + preloaded0_l_discount[D0]));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash10 = 0;
            unsigned long tmp_hash11 = hash("count_l_discount", 16);
            (hash10 = (hash10 + tmp_hash11));
            unsigned long tmp_pos43$ = (hash10 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos43$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos43$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos43$]], "count_l_discount", 16) != 0))) {
                (tmp_pos43$ = ((tmp_pos43$ + 1) & 255));
            }
            int key_pos43$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos43$];
            if ((key_pos43$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos43$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos43$] = key_pos43$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos43$] = "count_l_discount");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos43$] = 16);
                yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos43$], 0);
            }
            yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos43$], (yyjson_get_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos43$]) + 1));
            if ((key_pos0$ == 0)) {
                tmp22_key_count++;
                (key_pos0$ = tmp22_key_count);
                (tmp22_htable[tmp_pos0$] = key_pos0$);
                (tmp22_keys0[key_pos0$] = preloaded0_l_returnflag[D0]);
                (tmp22_keys1[key_pos0$] = preloaded0_l_linestatus[D0]);
                (tmp22__DEFAULT_[key_pos0$] = (struct tmp21 *)malloc(sizeof(struct tmp21) * 1));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_key_count = 0);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable = (int *)calloc(256, sizeof(int)));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0 = (const char **)malloc(sizeof(const char *) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0 = (int *)malloc(sizeof(int) * 256));
                (tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_ = (yyjson_val *)malloc(sizeof(yyjson_val) * 256));
            }
            unsigned long hash11 = 0;
            unsigned long tmp_hash12 = hash("count_order", 11);
            (hash11 = (hash11 + tmp_hash12));
            unsigned long tmp_pos48$ = (hash11 & 255);
            while (((tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos48$] != 0) && (compare_str2(tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos48$]], tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos48$]], "count_order", 11) != 0))) {
                (tmp_pos48$ = ((tmp_pos48$ + 1) & 255));
            }
            int key_pos48$ = tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos48$];
            if ((key_pos48$ == 0)) {
                tmp22__DEFAULT_[key_pos0$]->tmp21_key_count++;
                (key_pos48$ = tmp22__DEFAULT_[key_pos0$]->tmp21_key_count);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_htable[tmp_pos48$] = key_pos48$);
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_str0[key_pos48$] = "count_order");
                (tmp22__DEFAULT_[key_pos0$]->tmp21_keys_len0[key_pos48$] = 11);
                yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos48$], 0);
            }
            yyjson_set_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos48$], (yyjson_get_uint(&tmp22__DEFAULT_[key_pos0$]->tmp21__DEFAULT_[key_pos48$]) + 1));
        }
    }
    // print hashmap
    printf("{");
    for (int i = 0; i < tmp22_key_count; i++) {
        int key_pos = i + 1;
        // print key
        printf("\"");
        printf("%c", tmp22_keys0[key_pos]);
        printf("|");
        printf("%c", tmp22_keys1[key_pos]);
        printf("\"");
        printf(":");
        // print value
        if ((key_pos == 0)) {
            printf("null");
        } else {
            // print nested hashmap
            printf("{");
            for (int key_pos51 = 1; key_pos51 <= tmp22__DEFAULT_[key_pos]->tmp21_key_count; key_pos51++) {
                // print key
                printf("\"%.*s\"", tmp22__DEFAULT_[key_pos]->tmp21_keys_len0[key_pos51], tmp22__DEFAULT_[key_pos]->tmp21_keys_str0[key_pos51]);
                printf(":");
                // print value
                if ((key_pos51 == 0)) {
                    printf("null");
                } else {
                    // print json object
                    printf("%s", yyjson_val_write(&tmp22__DEFAULT_[key_pos]->tmp21__DEFAULT_[key_pos51], 0, NULL));
                }
                if (key_pos51 != tmp22__DEFAULT_[key_pos]->tmp21_key_count) {
                    printf(",");
                }
            }
            printf("}");
        }
        if (i != tmp22_key_count - 1) {
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
