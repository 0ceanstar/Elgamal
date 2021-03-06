#pragma once
#include <gmp.h>
#include <time.h>

struct elg_pk
{
    // b = a^t, p为素数
    mpz_t p, a, b;
};

struct elg_sk
{
    mpz_t t;
    mpz_t p, a, b;
};

class Elgamal
{
public:
    Elgamal();

    /**
     * @brief Get the elgamal public key  
     * 
     * @return elg_pk 
     */
    elg_pk get_elg_pk() { return pk; }

    /**
     * @brief Get the elgamal secret key
     * 
     * @return elg_sk 
     */
    elg_sk get_elg_sk() { return sk; }

    /**
     * @brief Use pk to encrypt messege m, get the ciphertext
     * 
     * @param c1 elgamal ciphertext_1
     * @param c2 elgamal ciphertext_2
     * @param m The messege you want to encrypt
     * @param pk elgamal public key
     */
    void elg_enc(mpz_t &c1, mpz_t &c2, mpz_t m, elg_pk pk);

    /**
     * @brief Use sk to decrypt ciphertext, get recovered messege m
     * 
     * @param m recovered messege m
     * @param c1 elgamal ciphertext_1
     * @param c2 elgamal ciphertext_2
     * @param sk secret key 
     */
    void elg_dec(mpz_t &m, mpz_t c1, mpz_t c2, elg_sk sk);

    /**
     * @brief To test the correctness
     * 
     */
    static void sample();

    static void sample_1();

private:
    elg_pk pk;
    elg_sk sk;
    static const int MESSEGE_SPACE = 512;
};
