if (Setting1::style3)
{
	if (Data::VehicleList.size() != 0)
	{
		TempVehicalList.clear();
		TempVehicalList = Data::VehicleList;
		for (Vehicle& Vehicle : Data::VehicleList)
		{
			Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Vehicle.Address + Offset::RootComponent) + Offset::Position);
			if (!Algorithm::WorldToScreen(Data::lOCALPLAYERPosotion, Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;
			if (Distance < 12 || Distance > 700)
			{
				continue;
			}

			if (Setting1::Vehicle)
			{
				Text = Vehicle.Name + "  (" + to_string(Distance) + "M)";

				std::string hp;
				if (Setting1::hp)
				{
					hp.append("Gas : ").append(std::to_string((int)(Vehicle.oil)).append(" - HP : ").append(std::to_string((int)(Vehicle.hp)).append("")));
					DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, hp, Screen.X - 0, Screen.Y + 20, Colors1::VehicleColorStyle3, true);

				}
				if (Setting1::feul)
				{
					//DX11::ImGui_DX11::DrawBlood(Screen.X - 30, Screen.Y + 17, 20.00f, 2.0, Vehicle.oil);
				}
				if (Setting1::vahicle_item && Vehicle.Name == "BRDM")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Scooter")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Motorcycle")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Snowmobile")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Tuk")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Buggy")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Sportsa")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Sports")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Dacia")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Rony")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::Esp_Item_AKM && Vehicle.Name == "UAZ")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::Esp_Item_AKM && Vehicle.Name == "Minibus")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::Esp_Item_AKM && Vehicle.Name == "PG117")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::Esp_Item_AKM && Vehicle.Name == "Aquarail")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::Esp_Item_AKM && Vehicle.Name == "Plane")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "UTV (Utility Terrain Vehicle)")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Monstar Truck")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
				if (Setting1::vahicle_item && Vehicle.Name == "Coupe-RB_New Dacia")
				{
					if (Vehicle.driving)
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

					}
					else
					{
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Setting1::VehicleSize, Text, Screen.X, Screen.Y, Colors1::VehicleColorStyle3, true);

					}
				}
			}
		}
	}
}
