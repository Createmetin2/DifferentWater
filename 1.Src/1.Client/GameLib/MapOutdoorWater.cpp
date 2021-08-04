//Search:

void CMapOutdoor::LoadWaterTexture()
{
	UnloadWaterTexture();
	char buf[256];
	for (int i = 0; i < 30; ++i)
	{
		sprintf(buf, "d:/ymir Work/special/water_0/%02d.dds", i + 1);
		m_WaterInstances[i].SetImagePointer((CGraphicImage*)CResourceManager::Instance().GetResourcePointer(buf));
	}
}

//Replace with:

void CMapOutdoor::LoadWaterTexture()
{
	UnloadWaterTexture();
	char buf[256];
	for (int i = 0; i < 30; ++i)
	{
#ifdef ENABLE_DIFFERENT_WATER
		if (!m_bSettingWaterType)
		{
			sprintf(buf, "d:/ymir Work/special/water/%02d.dds", i + 1);
		}
		else
		{
			sprintf(buf, "d:/ymir Work/special/water_%d/%02d.dds", GetWaterType(), i + 1);
		}
#else
		sprintf(buf, "d:/ymir Work/special/water/%02d.dds", i + 1);
#endif
		m_WaterInstances[i].SetImagePointer((CGraphicImage*)CResourceManager::Instance().GetResourcePointer(buf));
	}
}