#include <stdio.h>
#include <string.h>

#define TEST_MODE
#include "online_exam_final_persistent_fixed.c"

/* -------- Test Case 3: Save & Load Question -------- */
void test_save_and_load_question(void) {
    Question q;

    /* Create a test question */
    q.qid = 55;
    strcpy(q.text, "Is C a programming language?");
    strcpy(q.opt[0], "Yes");
    strcpy(q.opt[1], "No");
    strcpy(q.opt[2], "Maybe");
    strcpy(q.opt[3], "None");
    q.correct = 1;

    /* Save question to file */
    save_question_to_file(&q);

    /* Reload questions from file */
    load_questions_from_file();

    /* Verify question exists in memory */
    int found = 0;
    for (int i = 0; i < qcount; i++) {
        if (qbank[i].qid == 55) {
            found = 1;
            break;
        }
    }

    /* Test result */
    if (found)
        printf("TEST CASE 3 PASSED\n");
    else
        printf("TEST CASE 3 FAILED\n");
}
