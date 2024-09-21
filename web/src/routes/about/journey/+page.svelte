<script>
	import { MapLibre, DefaultMarker, Popup, GeoJSON, LineLayer } from 'svelte-maplibre';

	let mapClasses = '';
	let markers = [
		{
			lngLat: [-0.1709, 51.479],
			name: 'Marker 1'
		},
		{
			lngLat: [-0.177753459872946, 51.498208544108934],
			name: 'Marker 3'
		}
	];

	let data = {
		type: 'FeatureCollection',
		features: [
			{
				type: 'Feature',
				properties: {},
				geometry: {
					coordinates: [
						[-0.17029436886616622, 51.47877235398511],
						[-0.1758454622781187, 51.48446211324952],
						[-0.1747945558847448, 51.48500241090164],
						[-0.175359675624577, 51.48535180983828],
						[-0.17646402486727197, 51.48653164969471],
						[-0.17819844074713842, 51.4877296061122],
						[-0.17971660160876013, 51.4887727189066],
						[-0.1811038865349417, 51.491038147306455],
						[-0.18024010520895217, 51.49131520892257],
						[-0.17848636766126447, 51.49206488969375],
						[-0.17961189816969636, 51.49804559304056],
						[-0.177753459872946, 51.498208544108934]
					],
					type: 'LineString'
				}
			}
		]
	};
</script>

<svelte:head>
	<title>Home</title>
	<meta name="description" content="Svelte demo app" />
</svelte:head>

<MapLibre
	style="https://basemaps.cartocdn.com/gl/positron-gl-style/style.json"
	class={mapClasses}
	standardControls
	zoom={13}
	center={[-0.17514, 51.48973]}
>
	{#each markers as { lngLat, name }}
		<!-- Unlike the custom marker example, default markers do not have mouse events,
    and popups only support the default openOn="click" behavior -->
		<DefaultMarker {lngLat} draggable>
			<Popup offset={[0, -10]}>
				<div class="text-lg font-bold">{name}</div>
			</Popup>
		</DefaultMarker>
	{/each}

	<GeoJSON id="maine" {data}>
		<LineLayer
			layout={{ 'line-cap': 'round', 'line-join': 'round' }}
			paint={{
				'line-width': 5,
				'line-color': '#586F7C',
				'line-opacity': 0.8
			}}
		/>
	</GeoJSON>
</MapLibre>

<!-- <div class="back-arrow">
	<a href="/about" class="back-btn">
		<svg
			xmlns="http://www.w3.org/2000/svg"
			class="h-6 w-6"
			fill="none"
			viewBox="0 0 24 24"
			stroke="currentColor"
		>
			<path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 19l-7-7 7-7" />
		</svg>
	</a>
</div> -->

<div class="draw">
	<h1>Morning Cycle to Uni</h1>
	<div class="draw-body">
		<div class="text-column">
			<p><b>Distance:</b> 1.64km</p>
			<p><b>Time:</b> 10:05</p>
			<p><b>kCal:</b> 2001</p>
		</div>
		<div class="text-column">
			<p><b>Date:</b> 21/09/24</p>
			<p><b>Close Calls:</b> 4</p>
			<p><b>Elevation:</b> 20m</p>
		</div>
	</div>
</div>

<style>
	:global(.map) {
		height: 500px;
	}

	.draw {
		position: absolute;
		bottom: 0;
		left: 0;
		width: 100%;
		display: flex;
		height: 300px;
		background: #fff;
		border-radius: 30px 20px 0 0;
		box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
		flex-direction: column;
	}

	.draw-body {
		display: flex;
		justify-content: space-between;
		width: 100%;
		justify-content: center;
		text-align: center;
	}

	.back-arrow {
		position: absolute;
		top: 20px;
		right: 20px;
		z-index: 100;
		width: 50px;
		height: 50px;
		background: #fff;
		border-radius: 50%;
		box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
	}
</style>
