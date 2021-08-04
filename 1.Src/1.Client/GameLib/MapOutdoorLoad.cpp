//Search:

	CTerrain::SetTextureSet(&m_TextureSet);
	
	if (stTokenVectorMap.end() != stTokenVectorMap.find("environment"))
	{
		const CTokenVector & c_rEnvironmentVector = stTokenVectorMap["environment"];
		if (!c_rEnvironmentVector.empty())
			m_settings_envDataName = c_rEnvironmentVector[0];
		else
			TraceError("CMapOutdoor::LoadSetting(c_szFileName=%s) - Failed to load environment data\n", c_szFileName);
	}
	
//Add Under:

#ifdef ENABLE_DIFFERENT_WATER
	if (stTokenVectorMap.end() != stTokenVectorMap.find("watertype"))
	{
		m_bSettingWaterType = (bool)(atoi(stTokenVectorMap["watertype"][0].c_str()) != -1);
	}

	if (m_bSettingWaterType == true)
	{
		BYTE WaterType = atoi(stTokenVectorMap["watertype"][0].c_str());

		if (WaterType < 0)
		{
			TraceError("MapOutdoor::LoadSetting(c_szFileName=%s) -  ERROR. WATERTYPE CANNOT HAVE NEGATIVE VALUE.", c_szFileName);
			return false;
		} 

		SetWaterType(WaterType);
	}
	else
	{
		SetWaterType(m_bSettingWaterType);
	}
#endif