package com.mapbox.mapboxsdk.module.telemetry;

import com.google.gson.annotations.SerializedName;
import com.mapbox.android.telemetry.Event;

import android.os.Bundle;
import android.os.Parcel;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

public class PerformanceEvent extends Event {
  private static final String PERFORMANCE_TRACE = "performance.trace";

  @SerializedName("event")
  private final String event;

  @SerializedName("created")
  private final String created;

  @SerializedName("sessionId")
  private final String sessionId;

  @SerializedName("data")
  private final Bundle data;

  private static final SimpleDateFormat dateFormat =
          new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSSZ", Locale.US);

  PerformanceEvent(String sessionId, Bundle data) {
    this.event = PERFORMANCE_TRACE;
    this.created = dateFormat.format(new Date());
    this.sessionId = sessionId;
    this.data = data;
  }

  private PerformanceEvent(Parcel in) {
    this.event = in.readString();
    this.created = in.readString();
    this.sessionId = in.readString();
    this.data = in.readBundle();
  }

  @Override
  public int describeContents() {
    return 0;
  }

  @Override
  public void writeToParcel(Parcel parcel, int i) {
    parcel.writeString(event);
    parcel.writeString(created);
    parcel.writeString(sessionId);
    parcel.writeBundle(data);
  }

  public static final Creator<PerformanceEvent> CREATOR = new Creator<PerformanceEvent>() {
    @Override
    public PerformanceEvent createFromParcel(Parcel in) {
      return new PerformanceEvent(in);
    }

    @Override
    public PerformanceEvent[] newArray(int size) {
      return new PerformanceEvent[size];
    }
  };
}
