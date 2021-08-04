//Search:

		WORD						m_wPatchCount;
		
//Add Under:

#ifdef ENABLE_DIFFERENT_WATER
		BYTE m_bWaterType;
		const BYTE GetWaterType() { return m_bWaterType; }
		void SetWaterType(BYTE Type) { m_bWaterType = Type; }
#endif

//Search:

	private:
		bool m_bSettingTerrainVisible;

//Add Under:

#ifdef ENABLE_DIFFERENT_WATER
		bool m_bSettingWaterType;
#endif