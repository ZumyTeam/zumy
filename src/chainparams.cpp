// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"
#include "base58.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
//
class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x1a;
        pchMessageStart[1] = 0x2b;
        pchMessageStart[2] = 0x3c;
        pchMessageStart[3] = 0x4d;
        vAlertPubKey = ParseHex("04c244288a8c6ebbf491443ebfa121a365d71cb009f201c118b00cf8e77641c7f1e63e330ba909183749871275c0f5c1c7368e8d7e2066168c40ce3cb629cf212f");
        nDefaultPort = 20188;
        nRPCPort = 20182;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 18);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 18);

        const char* pszTimestamp = "What Is Nimbus? | JP Buntinx | August 3, 2018"; // Saturday, August 4, 2018 12:00:00 PM;
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].nValue = nGenesisBlockReward;
        vout[0].SetEmpty();
        CTransaction txNew(1, 1533384000, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = timeGenesisBlock;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 138374;

        /** Genesis Block MainNet */
        /**
    Hashed MainNet Genesis Block Output
    block.hashMerkleRoot == 8abd7958c819e31bf92515dadcc727d036a40119bf78edacf10b72db6f3d4e83
    block.nTime = 1533384000
    block.nNonce = 138374
    block.GetHash = 0000118a3f6e58a2cf7a51bac5c78e901f2594db7304b4fd13a8a5bd4568b659
        **/

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000118a3f6e58a2cf7a51bac5c78e901f2594db7304b4fd13a8a5bd4568b659"));
        assert(genesis.hashMerkleRoot == uint256("0x8abd7958c819e31bf92515dadcc727d036a40119bf78edacf10b72db6f3d4e83"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,144); // All Zumy Pubkey Addresses will begin with 'z' or '2'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,69); // All Zumy Script Addresses will begin with 'U' or 'V'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,52); // All Zumy Secret Addresses will begin with 'M' or 'N'
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,79); // All Zumy Stealth Addresses will begin with 'Y' or 'Z'
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

       // vSeeds.push_back(CDNSSeedData("someLabel",  "someIP"));
       // vSeeds.push_back(CDNSSeedData("someLabel",  "someIP"));
       // vSeeds.push_back(CDNSSeedData("someLabel",  "someIP"));
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPoolMaxTransactions = 3;
        strDarksendPoolDummyAddress = "RmTXZQ9W92y13UkyEoxcEsbjA6oZeQUFZu";
        nEndPoWBlock = 0x7fffffff;
        nStartPoSBlock = 0;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xa2;
        pchMessageStart[1] = 0xb3;
        pchMessageStart[2] = 0xc4;
        pchMessageStart[3] = 0xd5;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04ac24ab003c828cdd9cf4db2ebbde8e1cecb3bbfa8b3127f798659b84d44112080827ed45698648af9fe78abf42e316ace665879c553f099e55299d6b54edd7e0");
        nDefaultPort = 31337;
        nRPCPort = 30435;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime    = timeTestNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 80805;

        /** Genesis Block TestNet */
        /**
    Hashed TestNet Genesis Block Output
    block.hashMerkleRoot == 8abd7958c819e31bf92515dadcc727d036a40119bf78edacf10b72db6f3d4e83
    block.nTime = 1533384030
    block.nNonce = 80805
    block.GetHash = 00003ee0f57ed677ee96ea3402a863687ed0bc4ac69834091793cab13ec3ec00
        **/

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00003ee0f57ed677ee96ea3402a863687ed0bc4ac69834091793cab13ec3ec00"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,82); // All Zumy Pubkey Addresses will begin with 'Z' or 'Y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,131); // All Zumy Script Addresses will begin with 'u' or 'v'
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,111); // All Zumy secretkey Addresses will begin with 'm' or 'n'
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,141); // All Zumy stealth Addresses will begin with 'y' or 'x'
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nEndPoWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xa3;
        pchMessageStart[1] = 0xb4;
        pchMessageStart[2] = 0xc5;
        pchMessageStart[3] = 0xdd;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = timeRegNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = nNonceReg;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 73517;
        strDataDir = "regtest";

        /** Genesis Block TestNet */
        /**
        Hashed RegNet Genesis Block Output
        block.hashMerkleRoot == 8abd7958c819e31bf92515dadcc727d036a40119bf78edacf10b72db6f3d4e83
        block.nTime = 1533384090
        block.nNonce = 8
        block.GetHash = 135eab2fcace1b7d656016d460ac99a35e64c833885608b623a01f6dcdc9a29a
        **/

        assert(hashGenesisBlock == uint256("0x135eab2fcace1b7d656016d460ac99a35e64c833885608b623a01f6dcdc9a29a"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
