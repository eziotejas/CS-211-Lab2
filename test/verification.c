        }
        else

        {


                printf("A1 and A2 are not matching \n");






        }










        t0 = get_sec();
        block_lu(A3, B3, n,  block_size);
        t1 = get_sec();
        //printf("Elapsed time, block LU: %lf seconds\n", t1 - t0);

        //if (verify_matrix(A1, A3, n, n) || verify_matrix(B1, B3, n, 1))
        //    printf("my block LU is incorrect.\n");

        free(A1);
        free(A2);
        free(A3);
        free(B1);
        free(B2);
        free(B3);
    }

    return 0;
}
        
