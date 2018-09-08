// Copyright (c) 2016-2018 The Zumy Team / Zumy
// Copyright (c) 2018 The Zumy Team / Zumy project
// Copyright (c) 2018 The Zumy project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_MINING_H
#define BITCOIN_MINING_H

#include "bignum.h"

/** Minimum nCoinAge required to stake PoS */
static const unsigned int nStakeMinAge = 1 / 50; // 50 minutes
/** Time to elapse before new modifier is computed */
static const unsigned int nModifierInterval = 2 * 60;
/** Genesis block subsidy */
static const int64_t nGenesisBlockReward = 1 * COIN;
/** Reserve block subsidy */
static const int64_t nBlockRewardReserve = 5250000 * COIN; // 7% reserved for development
/** Starting block subsidy */
static const int64_t nBlockPoWReward = 18 * COIN;
/** PoW Superblock modifier */
static const int64_t nSuperModifier = 2;
/** PoS Reward */
static const int64_t COIN_YEAR_REWARD = 18 * CENT; // Corrected in v2.0.0.0+
/** PoS Superblock Reward */
static const int64_t COIN_SPRB_REWARD = 36 * CENT; // Corrected in v2.0.0.0+
/** Block spacing preferred */
static const int64_t BLOCK_SPACING = 2 * 60;
/** Block spacing minimum */
static const int64_t BLOCK_SPACING_MIN = 60;
/** Block spacing maximum */
static const int64_t BLOCK_SPACING_MAX = 3.5 * 60;
/** Desired block times/spacing */
static const int64_t GetTargetSpacing = BLOCK_SPACING;
/** Darksend collateral */
static const int64_t DARKSEND_COLLATERAL = (0.01*COIN);
/** Darksend pool values */
static const int64_t DARKSEND_POOL_MAX = (4999.99*COIN);
/** MasterNode required collateral */
inline int64_t MasternodeCollateral(int nHeight) { return 17500; } // .0175M ZMY required as collateral
/** Coinbase transaction outputs can only be staked after this number of new blocks (network rule) */
static const int nStakeMinConfirmations = 50;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int nCoinbaseMaturity = 30; // 30-TXs | 90-Mined

#endif // BITCOIN_MINING_H
