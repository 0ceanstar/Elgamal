#pragma once
#include "Elgamal.h"
#include <vector>
class thres_Elgamal : Elgamal
{
public:
    thres_Elgamal();

    /**
     * @brief Use pk to encrypt messege m, get the ciphertext
     *
     * @param c1 elgamal ciphertext_1
     * @param c2 elgamal ciphertext_2
     * @param m The messege you want to encrypt
     * @param pk elgamal public key
     */
    void thres_elg_enc(mpz_t &c1, mpz_t &c2, mpz_t m, elg_pk pk);

    /**
     * @brief Use sk to decrypt ciphertext, get recovered messege m
     *
     * @param m recovered messege m
     * @param c1 elgamal ciphertext_1
     * @param c2 elgamal ciphertext_2
     * @param sk secret key fragment
     */
    void thres_elg_dec(mpz_t &m, std::vector<mpz_t> frag, mpz_t c2);

    void get_dec_frag(std::vector<mpz_t> &frag, mpz_t c1, std::vector<mpz_t> ski);

    void get_sk_frag(std::vector<mpz_t> &ti);

private:
    std::vector<mpz_t> ti;
};
