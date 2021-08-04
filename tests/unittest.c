#include <stdlib.h>
#include "test_LinkerPar_reliability.h"

// Run unittest suite
int main(void) {
    int no_failed = 0;                   
    Suite *s;                            
    SRunner *runner;                     

    s = LinkerPar_reliability_suite();                   
    runner = srunner_create(s);          

    srunner_run_all(runner, CK_NORMAL);  
    no_failed = srunner_ntests_failed(runner); 
    srunner_free(runner);                      
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}