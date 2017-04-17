class ICE
{
    class vehicles
    {
		class armaments
        {
			startFullyRearmed = 1;
        };
    };
	class zones
	{
    #include "zoneList.hpp"
	};
	class mission
	{
		gameMode = "A&S";
		missionScale = "tiny";
		recommendedTotalPlayers = 25;

        class briefings
        {
			class west
			{
				original = "briefing_blue.hpp";
			};
			class east
			{
				original = "briefing_red.hpp";
			};
        };
		class factions // or sides
		{
			class faction
			{
				bluFor = "BLU_F";
				opFor = "OPF_G_F";
			};
			class teamName
			{
				bluFor = "Mercenaries";
				opFor = "Clear Sky";
			};
			class teamFlag
			{
				bluFor = "flags\Mercenaries.jpg"; // "flags" is a sub-folder in mission folder
				opFor = "flags\Clearsky.jpg";
			};
		};
		class scoring
		{
			class tickets
			{
				// In A&S, specify the tickets per hour
				// In A&D, Attacker = starting tickets, Defender = tickets per zone
				// In S&D, Attacker = starting tickets, Defender = # of caches
				bluFor = 130;
				opFor = 130;
			};
		};
	};
	class respawn
	{
        class vehicles
        {
            class respawnDelay
            {
                //'globalOverride' takes precedence over 'multiplier'
                //globalOverride = -1; // Value is in minutes. set to >= 0 to override scaled "vehicle category" values.
                multiplier = -1; // set to > 0 to override scaled "vehicle category" values. Eg: 0.5 to halve all values. 1.5 to increase all values.
                //(<= 0 uses default multiplier), (> 0, < 1 scales down), (> 1 scales up), (== 1 uses 1 for all vehicles, regardless of missionScale)
            };
        };
		class FO
		{
			minSpacingDist = 600;
			maxFriendlySiteDist = 700;
			minZoneDist = 120;
			minEnemyFBDist = 200;
			minEnemyBaseDist = 1700;
			minEnemyZoneDist = 350;
		};
		class SRP
		{
			maxFriendlySiteDist = 350;
			minEnemyBaseDist = 300;
			minZoneDist = 220;
		};
		class HO
		{
			minSpacingDist = 250;
			maxFriendlySiteDist = 350;
		};
        class infantry
        {
            baseDuration = 60;
            class unevenTeamsPenaltyTime
            {
                ratioDuration = 60; // "pivot value" where low player count differences result in small time penalties,
                // but large differences result in exponential time penalties
                maxDuration = 120;
            };
        };
	};
	class gameModes
	{
	    class objectives
        {
            class zones
            {
                class captureRates
                {
                    heldZoneMultiplier = 1.5; // Decimal value between 0 and N - <1 reduces capture rate, >1 increases capture rate
					neutralZoneMultiplier = 1.5; // This is a cumulative multiplier with 'heldZoneMultiplier'
					negateNeutral = 1.5; // set to 1 to make both Multipliers totally independent, not a "cumulative multiplier"
                };
            };
		};
        class AAS
		{
			class ticketBleedRate
			{
				bluFor = 100;
				opFor = 100;
			};
		};
	};
    class gear
    {
        #include "tb_kitDefines.sqh" 
        #include "tb_magazineExclusions.hpp"
	    class NVGogglesForAll
        {
            west = 1;
            east = 1;
            resistance = 0;
        };
        class roles
        {
			#define __unlimited -99
            kits[] =
            {
                #include "factions\BLU_F_roleRatio.hpp"
                #include "factions\OPF_F_roleRatio.hpp"
            };
		};
	    class armaments
		{
			class BLU_F
			{
				defaultGear = "factions\BLU_F.sqh";
				#include "factions\_common_smallItems.sqh"
				#include "factions\BLU_F_gear.sqh"
				#include "factions\BLU_F_uniforms.sqh"
			};
			class OPF_G_F
			{
				defaultGear = "factions\OPF_F.sqh";
				#include "factions\_common_smallItems.sqh"
				#include "factions\OPF_F_gear.sqh"
				#include "factions\OPF_F_uniforms.sqh"
			};
		};
	};
};
